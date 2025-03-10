// 랜덤 20개 수 출력
// 버블 정렬로 정렬 후 출력
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

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

    // qsort
    qsort(nums, 20, sizeof(nums[0]), compare);

    for (int i = 0; i < 20; ++i)
        printf("%d, ", nums[i]);
    printf("\n");
    return 0;
}