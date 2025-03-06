//구구구구구구단단단
#include <stdio.h>

int main(void)
{
    for(int i = 2; i <= 9; ++i) //2단부터 9단까지 i
    {
        printf("---------%d단---------\n", i);
        for(int j = 1; j <= 9; ++j) //2부터 9까지 j
        {
            printf("%d X %d = %d\n", i, j, i*j);
        }
    }
    return 0;
}