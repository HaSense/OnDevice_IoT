int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        int prevPrev = 0; // F(n-2)
        int prev = 1;     // F(n-1)
        int result = 0;   // F(n)

        for (int i = 2; i <= n; i++) {
            result = prevPrev + prev; // 점화식: F(n) = F(n-1) + F(n-2)
            prevPrev = prev; // 다음 반복을 위해 값 업데이트
            prev = result;   // 다음 반복을 위해 값 업데이트
        }

        return result;
    }
}

int main() {
    int n;
    printf("피보나치 수열의 항 번호를 입력하세요: ");
    scanf("%d", &n);
    printf("피보나치 수열의 %d번째 항의 값: %d\n", n, fibonacci(n));
    return 0;
}
