#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mpg123.h>
#include <ao/ao.h>
#include <pthread.h>

mpg123_handle *mh;
ao_device *dev;
unsigned char *buffer;
size_t buffer_size;
size_t done;
int err;
int driver;
ao_sample_format format;
int channels, encoding;
long rate;

// 재생을 위한 스레드 함수
void *play_music(void *arg) {
    // 파일 열기
    if (mpg123_open(mh, "NoMore.mp3") != MPG123_OK) {
        fprintf(stderr, "Unable to open MP3 file.\n");
        return NULL;
    }

    // 재생
    while (mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK) {
        ao_play(dev, buffer, done);
    }

    mpg123_seek(mh, 0, SEEK_SET); // 다음 재생을 위해 파일 포인터를 처음으로 이동
    return NULL;
}

int main() {
    int choice;
    pthread_t play_thread;

    ao_initialize();
    mpg123_init();
    mh = mpg123_new(NULL, &err);
    buffer_size = mpg123_outblock(mh);
    buffer = (unsigned char *) malloc(buffer_size * sizeof(unsigned char));

    driver = ao_default_driver_id();
    mpg123_open(mh, "NoMore.mp3");
    mpg123_getformat(mh, &rate, &channels, &encoding);

    memset(&format, 0, sizeof(format));
    format.bits = mpg123_encsize(encoding) * 8;
    format.rate = rate;
    format.channels = channels;
    format.byte_format = AO_FMT_NATIVE;
    format.matrix = 0;
    dev = ao_open_live(driver, &format, NULL);

    while (1) {
        printf("1. 노래 플레이\n2. 노래 멈춤\n3. 프로그램 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (pthread_create(&play_thread, NULL, play_music, NULL) != 0) {
                    fprintf(stderr, "Error creating thread\n");
                }
                break;
            case 2:
                if (pthread_cancel(play_thread) != 0) {
                    fprintf(stderr, "Error stopping thread\n");
                }
                // 재생 중인 스레드를 안전하게 종료
                pthread_join(play_thread, NULL);
                break;
            case 3:
                goto cleanup;
                break;
            default:
                printf("잘못된 선택입니다.\n");
        }
    }

cleanup:
    free(buffer);
    ao_close(dev);
    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();
    ao_shutdown();

    return 0;
}
