/* 사용법
  COPY src dst
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *sourceFile, *destFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // 인자의 개수 확인
    if (argc != 3) {
        fprintf(stderr, "사용법: %s 원본파일 대상파일\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // 원본 파일 열기
    sourceFile = fopen(argv[1], "rb");
    if (sourceFile == NULL) {
        perror("원본 파일을 열 수 없습니다");
        exit(EXIT_FAILURE);
    }

    // 대상 파일 열기
    destFile = fopen(argv[2], "wb");
    if (destFile == NULL) {
        perror("대상 파일을 열 수 없습니다");
        fclose(sourceFile); // 원본 파일 닫기
        exit(EXIT_FAILURE);
    }

    // 원본 파일에서 데이터를 읽고 대상 파일에 쓰기
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    // 파일 닫기
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
