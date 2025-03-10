// 랜덤 20개 수 출력
// 버블 정렬로 정렬 후 출력
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int nums[20] = {0};
    srand(time(NULL));
    for (int i = 0; i < 20; ++i)
    {
        nums[i] = rand() % 101;
    }
    for (int i = 0; i < 20; ++i)
        printf("%d, ", nums[i]);
    printf("\n");

    // 버블

    for (int i = 20 - 1; i >= 1; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 20; ++i)
        printf("%d, ", nums[i]);
    printf("\n");
    return 0;
}