#include <stdio.h>

int main(void)
{
    char ch;
    char str[100];

    printf("문자를 입력하시오 (getc(stdin)): ");
    ch = getc(stdin); // 표준 입력 버퍼에서 문자를 '하나' 가져옴
    printf("입력한 문자 : %c\n문자 입력(getc>getchar) : ", ch);

    ch = getc(stdin);
    ch = getchar();
    printf("입력한 문자 : %c \n 문자열 입력(scanf) : ", ch);

    scanf("%s%*c", str);
    printf("입력한 문자열 : %s\n", str);
    // 버퍼에 개행 문자가 있음
}