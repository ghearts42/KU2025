#include <stdio.h>

int main(void)
{
    char sentence[100];
    printf("문장 입력 : ");
    gets(sentence);
    int count = 0;
    printf("%s", sentence);
    for (int i = 0; i < 99; ++i)
    {
        if (91 > sentence[i] && sentence[i] > 64)
        {
            sentence[i] += 32;
            count += 1;
        }
        else if (sentence[i] == 0)
        {
            break;
        }
    }
    printf("바뀐 문장 : %s\n", sentence);
    printf("바뀐 문자 수 : %d\n", count);
}