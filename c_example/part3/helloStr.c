// 문자열 출력 방법
#include <stdio.h>

int main(void)
{
    char *str1 = "hellow";  // 이 형태의 문자열을 변경 불가능
    char str2[] = "hellow"; // 변경 가능한 문자열, 마지막에 NULL이 포함되어 있으므로 크기는 7으로 잡힘
    char str3[] = {'h', 'e', 'l', 'l', 'o', 'w', '\0'};
    char str4 = 'h';

    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);
    printf("%c\n", str4);

    printf("%p\n", &str1);
    printf("%p\n", &str2);
    printf("%p\n", &str3);
    printf("%p\n", &str4);

    // str1[-]은 변경 불가능이므로 컴파일 시 오류 발생함
    str2[0] = 'H';
    printf("%s\n", str2);
    return 0;
}