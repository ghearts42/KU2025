#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    printf("i : ");
    scanf("%d", &i);
    char *str1 = "apple";
    char str2[] = "apple";
    char *str3;
    char *str4;
    str3 = (char *)malloc(sizeof(char) * 6);
    str4 = (char *)malloc(sizeof(char) * i);
    printf("str4 : ");
    scanf("%s", str4);

    strcpy(str3, str2);
    printf("apple : %s address: %p\n", "apple", "apple");

    printf("str1 : %s adress: %p\n", str1, str1);
    printf("str1[1] : %c adress: %p\n", str1[1], str1 + 1);
    printf("str2 : %s adress: %p\n", str2, str2);
    printf("str2[1] : %c adress: %p\n", str2[1], str2 + 1);
    printf("str3 : %s adress: %p\n", str3, str3);
    printf("str3[1] : %c adress: %p\n", str3[1], str3 + 1);
    printf("str4 : %s adress: %p\n", str4, str4);
    printf("str4[1] : %c adress: %p\n", str4[1], str4 + 1);

    free(str3);
    free(str4);
    return 0;
}