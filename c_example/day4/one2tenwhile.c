// 1부터 10까지 출력하는 코드를 while문을 사용해 작성
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int i = 0;
    while (true)
    {
        printf("%d번째 출력\n", i + 1);
        ++i;
        if (i < 10)
        {
            break;
        }
    }
    return 0;
}