#include <stdio.h>

void increase() {
    int x = 10;
    x += 1;
    printf("increase 내 x: %d\n", x);
}

int main() {
    int x = 5;
    printf("main 시작 시 x: %d\n", x);
    increase();
    printf("increase 호출 후 x: %d\n", x);
    return 0;
}
