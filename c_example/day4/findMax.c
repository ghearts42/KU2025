// 10개의 랜덤한 0~100의 배열에서 가장 높은 값을 프린트하라

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int arr[10] = {0};
    int max = 0;
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 10; ++i)
    {
        arr[i] = rand() % 101;
        printf("%d \n", arr[i]);
        for (int j = 0; j < 10; ++j)
        {
            if (max < arr[i])
            {
                max = arr[i];
            }
        }
    }
    printf("가장 큰 숫자 : %d\n", max);
    return 1;
}