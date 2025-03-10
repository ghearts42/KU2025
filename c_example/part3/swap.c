#include <stdio.h>

int main(void)
{
    int a, b;
    int temp = 0;
    a = 10;
    b = 20;
    printf("a : %d, b : %d", a, b);

    // swap
    // swap(a,b);
    temp = a;
    a = b;
    b = temp;

    printf("a : %d, b : %d", a, b);
    return 0;
}