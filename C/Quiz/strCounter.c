#include <stdio.h>
#include <string.h>



int main()
{
    char str[100];
    scanf("%s", str);
    int n = strlen(str); //문자의 길이

    int bigCnt=0, smallCnt=0, numCnt=0, specialCnt=0;

    for(int i=0; i<n; i++){
        if(str[i]>='A' && str[i]<='Z')
            bigCnt++;
        else if(str[i]>='a' && str[i]<='z')
            smallCnt++;
        else if(str[i]>='0' && str[i]<='9')
            numCnt++;
        else
            specialCnt++;
    }

    printf("대문자 : %d\n", bigCnt);
    printf("소문자 : %d\n", smallCnt);
    printf("숫자 : %d\n", numCnt);
    printf("특수문자 : %d\n", specialCnt);
    return 0;
}
