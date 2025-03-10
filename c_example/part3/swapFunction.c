#include <stdio.h>

void swap(int *pA, int *pB); // 주소값을 받아오므로 return 불필요

int main(void)
{
    int a, b;
    a = 100;
    b = 200;
    printf("a : %d\tb : %d", a, b);
    swap(&a, &b); // int *pA = &a ...
    printf("a : %d\tb : %d", a, b);
    return 0;
}

void swap(int *pA, int *pB)
{
    int temp = *pA;
    *pA = *pB;
    *pB = temp;
}