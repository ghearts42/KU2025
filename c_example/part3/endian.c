// Big/littel Endian

#include <stdio.h>

int main(void)
{
    int a = 0x12345678;
    char *pA;
    pA = (char *)&a;
    printf("*pA : 0x%x\n", *pA);
    // 78 = Bigendian, 12 = littelendian
    return 0;
}