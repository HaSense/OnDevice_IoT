#include <stdio.h>

void counter() {
    int count = 0;
    count += 1;
    printf("count: %d\n", count);
}

int main() {
    for(int i = 0; i < 3; i++) {
        counter();
    }
    return 0;
}
예상 답안:
