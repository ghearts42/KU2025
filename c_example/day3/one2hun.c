#include <stdio.h>

int main(void)
{
    int sum = 100;
    for (int i = 0; i < 9901; ++i)
    {
        sum += i + 100;
    }
    printf("100부터 10000까지의 합 : %d\n", sum);
    return 0;
}