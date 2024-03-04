//
// Created by iot on 24. 3. 4.
//
#include "myUtil.h"
#include <stdio.h>
void Swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}