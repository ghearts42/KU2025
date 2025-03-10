#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}
int substract(int a, int b)
{
    return a - b;
}
int main(void)
{
    int x = 9;
    int y = 6;
    printf("add(x,y) : %d\n", add(x, y));
    printf("substract(x,y) : %d\n", substract(x, y));

    // 함수 포인터
    int (*fp)(int, int);
    fp = &add; // 함수 주소를 포인터에 연결함
    fp = add;  // 함수 주소를 포인터에 연결함
    printf("add(x,y) : %d\n", (*fp)(x, y));
    fp = &substract;
    printf("substract(x,y) : %d\n", fp(x, y));
    return 0;
}