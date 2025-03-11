#include <stdio.h>

int main(void)
{
    FILE *a;
    a = fopen("test.dat", "w");
    if (a == NULL)
    {
        printf("can't open file\n");
        return 1;
    }
    fprintf(a, "이 것 은 파 일 로 저 장 되 는 예 시 데 이 터 입 니 다 람 쥐 .");
    fclose(a);
    return 0;
}