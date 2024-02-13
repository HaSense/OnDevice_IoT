#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 난수 발생기 초기화
    srand(time(NULL)); // 현재 시간을 시드 값으로 사용

    // 0부터 99까지의 난수 생성
    int randomNumber = rand() % 100;

    printf("Generated random number: %d\n", randomNumber);

    return 0;
}
