// n개 숫자 배열의 평균값을 소수점 2자리까지

// 헤더
// VLA(Variable length array)/ 자제하라
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5
#define MAXC 100

// 메인함수
int main(void)
{
    int max_input;
    printf("배열 길이:");
    scanf("%d", &max_input);
    int scores[max_input];
    srand((unsigned int)time(NULL));
    int sum = 0;
    double average;
    for (int i = 0; i < MAX; ++i)
    {
        scores[i] = rand() % (MAXC + 1);
        printf("%d ,", scores[i]);
        sum += scores[i];
    }
    average = (double)sum / MAX;
    printf("평균은 : %.2f\n", average);
}