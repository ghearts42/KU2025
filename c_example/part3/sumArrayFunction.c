#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sumArray(int pArray[], int size);

int main(void)
{
    int nums[20] = {0};
    srand(time(NULL));
    for (int i = 0; i < 20; ++i)
    {
        nums[i] = rand() % 101;
    }

    int sum = sumArray(nums, sizeof(nums) / sizeof(int));
    printf("%d\n", sum);
    return 0;
}

int sumArray(int pArray[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += pArray[i];
    }
    return sum;
}