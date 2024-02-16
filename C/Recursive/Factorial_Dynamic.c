#include <stdio.h>

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i; // 점화식: result = result * i
    }
    return result;
}

int main() {
    int number;
    printf("양의 정수를 입력하세요: ");
    scanf("%d", &number);
    printf("%d! = %d\n", number, factorial(number));
    return 0;
}
