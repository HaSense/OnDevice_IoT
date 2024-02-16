#include <stdio.h>

int factorial(int n) {
    if (n == 0)
        return 1;
    else 
        return n * factorial(n - 1);
}

int main() {
    int number;
    printf("양의 정수를 입력하세요: ");
    scanf("%d", &number);
    printf("%d! = %d\n", number, factorial(number));
    return 0;
}
