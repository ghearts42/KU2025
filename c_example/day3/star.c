//별그려
#include <stdio.h>

int main(void)
{
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            printf("*");
        }
        printf("\n");
    }

    //피라미드 my

    for(int k = 0; k < 5; ++k)
    {
        for(int l = 0; l + k < 4; ++l)
        {
            printf(" "); // 4 3 2 1 0 순으로
        }
        for (int m = 7; m + 2*k >= 7 ; --m)
        {
            printf("*"); // 8 6 4 2 로 줄어듬 , m + 2 * k가 7보다 크거나 같은 동안만 반복함
        }
        printf("\n");
    }

    //피라미드의 정석

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i;j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i * 2 + 1; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
// 5 6 7 8 9
    return 0;
}