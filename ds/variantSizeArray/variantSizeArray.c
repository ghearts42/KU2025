#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int size;
    scanf("%d", &size);

    // int array[size];
    int *pArr = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; ++i)
    {
        // *(pArr + i) = i + 1;
        pArr[i] = i + 1;
    }

    for (int i = 0; i < size; ++i)
    {
        printf("%d", *(pArr + i));
        // printf("%d", pArr[i]);
    }

    printf("\n");

    free(pArr);

    return 0;
}