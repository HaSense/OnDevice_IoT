#include <stdio.h>
#include <stdlib.h>
#include <mpg123.h>
#include <ao/ao.h>
#include <pthread.h>

#define BITS 8

volatile int playing = 0; // 음악 재생 상태를 제어하는 전역 변수

mpg123_handle *mh;
unsigned char *buffer;
size_t buffer_size;
size_t done;
int err;

int driver;
ao_device *dev;
ao_sample_format format;
int channels, encoding;
long rate;

void cleanup(void *arg) {
    free(buffer);
    ao_close(dev);
    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();
    ao_shutdown();
}

void *play_music(void *arg) {
    pthread_cleanup_push(cleanup, NULL); // 스레드 종료 시 정리 함수 설정

            while (playing) {
                if (mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK) {
                    ao_play(dev, buffer, done);
                } else {
                    // 파일의 끝에 도달하거나 읽기 오류 발생 시 처음부터 다시 시작
                    mpg123_seek(mh, 0, SEEK_SET);
                }
            }

    pthread_cleanup_pop(1); // 정리 함수 실행 및 스레드 종료
    return NULL;
}

int main() {
    // 초기화
    ao_initialize();
    mpg123_init();
    mh = mpg123_new(NULL, &err);
    buffer_size = mpg123_outblock(mh);
    buffer = (unsigned char*) malloc(buffer_size * sizeof(unsigned char));

    // 오디오 드라이버 및 MP3 파일 열기
    driver = ao_default_driver_id();
    mpg123_open(mh, "/home/iot/workspace/data/mp3/nomore.mp3");
    mpg123_getformat(mh, &rate, &channels, &encoding);

    // 오디오 포맷 설정
    format.bits = mpg123_encsize(encoding) * BITS;
    format.rate = rate;
    format.channels = channels;
    format.byte_format = AO_FMT_NATIVE;
    format.matrix = 0;
    dev = ao_open_live(driver, &format, NULL);

    pthread_t music_thread;

    // 메뉴 출력 및 제어
    int choice;
    do {
        printf("1. 노래 듣기\n2. 노래 멈춤\n3. 종료\n선택:");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if (!playing) {
                    playing = 1; // 음악 재생 시작
                    if(pthread_create(&music_thread, NULL, play_music, NULL)) {
                        fprintf(stderr, "스레드 생성 에러\n");
                        return 1;
                    }
                }
                break;
            case 2:
                if (playing) {
                    playing = 0; // 음악 재생 중지
                    pthread_join(music_thread, NULL); // 음악 재생 스레드가 종료될 때까지 기다림
                }
                break;
            case 3:
                // 앱 종료
                printf("프로그램을 종료합니다.\n");
                if (playing) {
                    playing = 0;
                    pthread_join(music_thread, NULL);
                }
                break;
            default:
                printf("메뉴를 잘못 입력 하였습니다. 다시 입력해 주세요.\n");
        }
    } while(choice != 3);

    return 0;
}
