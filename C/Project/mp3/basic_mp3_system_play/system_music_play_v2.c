/*
 2024.02.27
 현재 프로그램은 앞의 v1의 문제를 해결하였으나 여전히 버그가 있다.
 mpg123 ~/workspace/data/mp3/nomore.mp3 > /dev/null &
 
 > /dev/null:

 >를 출력 방향이다. 그런데 /dev/null은 아무것도 없는 디바이스니깐 의미는 무시하라는 것이다.
 그래서 동작은 하나 메뉴가 나오지 않는다.
 강제로 2번을 입력하면 메뉴가 나오고 동작도 하지만 이것도 버그처럼 보인다.
 */


#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;

    while(1) { // 무한 루프
        printf("1. 노래 듣기\n2. 노래 멈춤\n3. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // mpg123를 사용하여 ~/workspace/data/mp3/nomore.mp3 재생
                // 표준 입력을 /dev/null로 리다이렉트하여 백그라운드에서 실행
                system("mpg123 ~/workspace/data/mp3/nomore.mp3 > /dev/null &");
                break;
            case 2:
                // 모든 mpg123 프로세스를 종료하여 재생 중인 노래 멈춤
                system("killall mpg123");
                break;
            case 3:
                printf("프로그램을 종료합니다.\n");
                exit(0); // 프로그램 종료
            default:
                printf("잘못된 선택입니다.\n");
        }
    }

    return 0; // 이 코드는 절대 실행되지 않습니다.
}
