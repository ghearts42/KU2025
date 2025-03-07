// 배열을 int로 만들어 랜덤한 값(0~100)을 입력하고 합을 구하기

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int A[10] = {0};
    int sum = 0;
    srand(time(NULL));

    for (int i = 0; i < 10; ++i)
    {
        A[i] = rand() % 100 + 1;
        sum += A[i];
        printf("%d 번 숫자 : %d\n", i + 1, A[i]);
    }
    printf("합 : %d\n", sum);
}