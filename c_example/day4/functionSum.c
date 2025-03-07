// 매개변수 2개를 int로 받아 더한 값을 출력하는 함수
#include <stdio.h>

int sum(int a, int b);

int main(void)
{
    int a = 10;
    int b = 20;
    int result = sum(a, b);
    printf("합 : %d\n", result);
    return 0;
}

int sum(int a, int b)
{
    int temp;
    temp = a + b;
    return temp;
}