#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
    char str[80];
    printf("문자열 입력 : ");
    gets(str);
    puts("입력 문자열 :");
    puts(str);

    return 0;
}