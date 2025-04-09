#include "qsort.h"

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int randomNumber(int *nums)
{
    srand(time(NULL));
    for (int i = 0; i < 20; ++i)
    {
        nums[i] = rand() % 101;
    }
    for (int i = 0; i < 20; ++i)
        printf("%d, ", nums[i]);
    printf("\n");
}

int randomQsort(int *nums)
{
    // qsort
    qsort(nums, 20, sizeof(nums[0]), compare);
    for (int i = 0; i < 20; ++i)
        printf("%d, ", nums[i]);
    printf("\n");
}