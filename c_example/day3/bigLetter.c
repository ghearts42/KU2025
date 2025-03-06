// 임의의 문자를 scanf 받아 대문자인지 소문자인지 출력하기
#include <stdio.h>

int main()
{
    char letter;
    printf("임의의 문자 입력 : ");
    scanf("%c", &letter);

    if (90 >= letter && letter >= 65)
    {
        printf("%c는 대문자\n", letter);
    }
    else if (122 >= letter && letter >= 97)
    {
        printf("%c는 소문자\n", letter);
    }
    else
    {
        printf("몰라레후\n");
    }
    return 0;
}

// 65부터 90까지이다.
// • 영어 알파벳 소문자 a부터 z까지의 아스키 코드 값은 97부터 122