// 배열을 활용하여 1~6까지의 주사위를 던지는 코드를 작성하시오.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int dice[10];
    srand(time(NULL));
    // 배열에 값 입력
    for (int i = 0; i < 10; ++i)
    {
        dice[i] = rand() % 6 + 1;
        printf("눈 : %d\n", dice[i]);
        printf("주솟값 : %p\n", &dice[i]);
    }
    printf("\n");
    // 각 배열을 변경
    for (int i = 0; i < 10; ++i)
    {
        dice[i] *= 10;
        printf("눈 : %d\n", dice[i]);
        printf("주솟값 : %p\n", &dice[i]);
    }
    printf("\n");
    return 0;
}