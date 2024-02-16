#include <stdio.h>

int executeSum(int kor, int eng, int math)
{
   return kor + eng + math;
}
double executeAvg(int _total)
{
    return (double)_total / 3.0;
}
int main()
{
    int kor, eng, math;
    scanf("%d %d %d", &kor, &eng, &math);
    int total = executeSum(kor, eng, math);
    printf("총점 : %d\n", total);
    printf("평균 : %.2f\n",executeAvg(total));
    return 0;
}
