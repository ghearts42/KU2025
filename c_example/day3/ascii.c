//1~127까지의 아스키코드 출력하기
//2중 for문
//8줄 출력

#include <stdio.h>

int main(void)
{
    char ch;
    for(int i = 0;i <= 7;++i)
    {
        printf("\n");
        for(int j = 0; j <= 15; ++j)
        {
            ch = i * 16 + j;
            printf("%d = %c  ", ch, ch);
        }    
    }
    return 0;
}