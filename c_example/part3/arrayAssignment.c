#include <stdio.h>

int main(void)
{
    int num[] = {1, 2, 3, 4, 5};
    int num2[5];

    // num[] = num2[]와 같은 형식으로 작성 불가능
    // num2 = num;
    for (int i = 0; i < 5; ++i)
    {
        num2[i] = num[i];
    }

    printf("num 의 주소값 %p\n", &num[0]);
    printf("num2 의 주소값 %p\n", &num2[0]);
    // 서로 독립적인 메모리이다
    num2[3] = 13;
    for (int i = 0; i < 5; ++i)
    {
        printf("num[%d] : %d\n", i, num[i]);
        printf("num2[%d] : %d\n", i, num2[i]);
    }

    // shallow copy
    int *num3;
    num3 = num;
    num3[2] = 23;
    printf("num3의 주소값 : %p\n", num3);
    for (int i = 0; i < 5; ++i)
    {
        printf("num[%d] : %d\n", i, num[i]);
        printf("num2[%d] : %d\n", i, num2[i]);
        printf("num3[%d] : %d\n", i, num3[i]);
    }

    return 0;
}