#include <stdio.h>

int main()
{
    int ch;

    ch = getchar();
    printf("입력 문자 : %c , %d\n", ch, ch);
    putchar(ch);
    putchar('\n');
}