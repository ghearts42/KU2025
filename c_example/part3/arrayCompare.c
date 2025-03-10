#include <stdio.h>

int main(void)
{
    int num[] = {1, 2, 3, 4, 5};
    int num2[] = {1, 2, 3, 4, 5};

    if (num == num2)
    {
        printf("num과 num2는 같다.");
    }
    else
    {
        printf("num과 num2는 다르다.");
    }

    int i;
    for (i = 0; i < 5; ++i)
    {
        if (num[i] != num2[i])
            break;
    }
    if (i == 5)
    {
        printf("num과 num2의 원소는 모두 같다.");
    }
    else
    {
        printf("num과 num2의 원소는 모두 다르다.");
    }
    return 0;
}