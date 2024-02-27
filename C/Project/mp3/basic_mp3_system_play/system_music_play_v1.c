/*
  2024.02.27 

  Ubuntu에서 가장 mp3를 play하는 방법 중 mpg123 유틸이 있다.
  $> sudo apt install mpg123
  
  Ubuntu 22.04에서 가장 쉽게 프로그램을 실행하는 법 활용하기에 따라 여러 프로그램에 활용할 수 있다.
  현재 버전은 버그가 있다. system()함수는 Ubuntu에서 다른 프로세스를 가진 프로그램을 실행 시키는 것인데 
  문제는 mpg123 프로그램이 동작되면서 내 프로그램이 정상동작 되지 않는다.
  이를 해결하도록 프로그램을 수정해야 한다.

  버그상태를 빠져나오려면 ctrl+z로 나오면 된다.
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
                system("mpg123 ~/workspace/data/mp3/nomore.mp3 &");
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
