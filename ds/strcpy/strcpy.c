#include <stdio.h>

// void my_strcpy(char *des, const char *src)
// {
//     int i;
//     for (int i = 0; src[i] /*!= '\0'*/; ++i)
//     {
//         des[i] = src[i];
//     }
//     des[i] = '\0';
// }
// OR
// void my_strcpy(char *des, const char *src)
// {
//     while (*src)
//     {
//         *des++ = *src++;
//     }
//     *des = '\0';
// }
// OR
void my_strcpy(char *des, const char *src)
{
    while (*des++ = *src++)
        ;
}

int main(void)
{
    char str[100];
    char *str2 = "hello Wolrd";
    my_strcpy(str, str2);
    printf("str2: %s\n", str2);

    return 0;
}