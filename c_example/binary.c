#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t number;
    scanf("%d", &number);
    int data = number;
    int count = 0;
    while (1)
    {
        data = data / 2;
        count += 1;
        if (data == 1)
        {
            break;
        }
    }

    for (count; count >= 0; --count)
    {
        if ((number >> count) & 0x01 == 1)
        {
            printf("세");
        }
        else
        {
            printf("나");
        }
    }
    return 0;
}