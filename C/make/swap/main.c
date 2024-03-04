#include <stdio.h>
#include "myUtil.h"

int main()
{
    int a=100, b=200;
    Swap(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}
