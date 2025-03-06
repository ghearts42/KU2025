// 1부터 10까지 연속하여 출력하는 for문 기초 코드

#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 10 ; ++i)
    {
        printf("출력한 숫자 : %d\n", i + 1);
    }
    return 0;
}