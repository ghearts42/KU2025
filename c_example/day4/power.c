// N의 제곱을 구하는 함수를 작성하여 2의 62승을 출력하시오.

#include <stdio.h>

long long power(int a, int b);
void power2(int a, int b, long long *result);

int main(void)
{
    int a = 2;
    int b = 62;
    long long result = power(a, b);
    printf("2의 62승 : %lld\n", result);
    long long result2 = 1;
    power2(a, b, &result2);
    printf("2의 62승 : %lld\n", result2); // 주소를 참조하면 메모리를 불러올때 데이터를 절약할 수 있다.
    return 0;
}

long long power(int a, int b)
{
    long long temp = 1;
    for (int i = 0; i < b; i++)
    {
        temp *= a;
    }
    return temp;
}

void power2(int a, int b, long long *result)
{
    *result = 1;
    for (int i = 0; i < b; i++)
    {
        *result *= a;
    }
}