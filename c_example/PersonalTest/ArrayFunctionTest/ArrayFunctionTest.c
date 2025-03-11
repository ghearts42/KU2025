#include <stdio.h>

void print_ary(int *pa)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("%d", pa[i]);
    }
}