#include <stdio.h>
#include <stdlib.h>
#include <mpg123.h>
#include <ao/ao.h>

#define BITS 8

int main() {
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

    // 초기화
    ao_initialize();
    mpg123_init();
    mh = mpg123_new(NULL, &err);
    buffer_size = mpg123_outblock(mh);
    buffer = (unsigned char*) malloc(buffer_size * sizeof(unsigned char));

    // 오디오 드라이버 및 MP3 파일 열기
    driver = ao_default_driver_id();
    mpg123_open(mh, "nomore.mp3");
    mpg123_getformat(mh, &rate, &channels, &encoding);

    // 오디오 포맷 설정
    format.bits = mpg123_encsize(encoding) * BITS;
    format.rate = rate;
    format.channels = channels;
    format.byte_format = AO_FMT_NATIVE;
    format.matrix = 0;
    dev = ao_open_live(driver, &format, NULL);

    // 메뉴 출력 및 제어
    int choice;
    do {
        printf("1. Music Play\n2. Music Stop\n3. App Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                // 음악 재생
                while (mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK) {
                    ao_play(dev, buffer, done);
                }
                mpg123_seek(mh, 0, SEEK_SET); // 다시 시작을 위해 파일 포인터 재설정
                break;
            case 2:
                // 음악 정지 (실제로는 다음 재생을 위해 파일 포인터를 재설정합니다)
                mpg123_seek(mh, 0, SEEK_SET);
                break;
            case 3:
                // 앱 종료
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);

    // 정리
    free(buffer);
    ao_close(dev);
    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();
    ao_shutdown();

    return 0;
}
