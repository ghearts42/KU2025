#include "Mystring.h"
#include <stdio.h>

int main(void)
{
    char str[40];
    scanf("%s", str);
    int len = my_strlen(str);
    printf("len of str : %d", len);

    char str2[40];
    my_strcpy(str2, str);
    printf("%s\n", str2);

    if (my_strcmp(str2, str) == 0)
        printf("두 문자열의 내용은 같다.");
    else
        printf("두 문자열의 내용은 다르다.");

    my_strcat(str2, "----");
    my_strcat(str2, str);
    printf("%s\n", str2);
    return 0;
}