#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;

    int *pa;
    *pa = a;
    int *pb;
    pb = &b;

    printf("%d, %d\n", *pa, *pb);

    int c = 10;
    int *pc = &c;
    *pc = 20;
    printf("%d", *pc);
}