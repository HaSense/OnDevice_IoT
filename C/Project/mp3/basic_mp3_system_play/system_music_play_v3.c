/*
 24.02.27
 오직 리눅스 스크립트 명령어를 이용하여 동작하는 프로그램이다.
 파이썬으로 가장 많이 사용하는 프로그램이 이 C 프로그램처럼 하여 시스템을 다루는 것이다.
 클라우드 관리 및 간단한 샘플 프로그램을 만드는 직업들이 있다.

 현재 프로그램은
 2>&1 &
 2 : 표준에러(stderr)을 뜻한다.
 1 : 표준출력(stdout)을 뜻한다. 하지만 현재 구문에서 그냥 2>1로 표시한다면 1은 파일1을 뜻하게 되므로 꼭 &1로 해야 stdout를 뜻하게 된다.
 즉 표준에러의 출력을 표준출력쪽으로 같이 출력하라는 뜻이다. 
 마지막의 &는 이를 백그라운드로 동작하라는 의마가 된다.
  */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;

    while(1) { 
        printf("1. 노래 듣기\n2. 노래 멈춤\n3. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
              // 표준 출력과 표준 에러를 모두 /dev/null로 리다이렉트
                system("mpg123 ~/workspace/data/mp3/nomore.mp3 > /dev/null 2>&1 &");
                break;
            case 2:
                system("killall mpg123");
                break;
            case 3:
                printf("프로그램을 종료합니다.\n");
                exit(0); 
            default:
                printf("잘못된 선택입니다.\n");
        }
    }

    return 0; 
}
