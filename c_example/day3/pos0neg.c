//숫자를 입력 받아 양수, 0, 음수를 출력하는 프로그램
// if else 사용
// printf는 한번만 사용
#include <stdio.h>

int main(void)
{
    int num = 0;
    char *output;
    scanf("%d", &num);
    if (num > 0)
    {
        output = "양수";
    }
    else if (num < 0)
    {
        output = "음수";       
    }
    else
    {
        output = "0";       
    }
    printf("숫자 %d (은)는 %s 입니다.", num, output);
    return 0;
}