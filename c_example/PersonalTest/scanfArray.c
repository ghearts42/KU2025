#include <stdio.h>

int main(void)
{
    int a[5] = {0};
    for (int i = 0; i < 5; ++i)
    {
        printf("숫자 : ");
        // scanf("%d", a + i);
        scanf("%d", &a[i]);
        printf("%d\n", a[i]);
    }
    printf("숫자 2 : ");
    // scanf("%d", a + i);
    scanf("%d", a);
    printf("%d\n", a[0]);
}