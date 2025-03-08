#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;

    int *pa;
    int pa = &a;
    int *pb;
    int pb = &b;

    printf("%d, %d\n", *pa, *pb);
}