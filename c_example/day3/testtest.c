#include <stdio.h>

int main()
{
    int sum = 0; // 합계를 위한 변수 선언
    int num = 0;
    do
    {
        sum += num; // sum에 현재 sum과 lcnt 더한 값을 대입
        printf("정수를 입력하세요. [음수 입력하면 종료]\n");
        scanf("%d", &num);
    } while (num >= 0); // 루프 카운터가 num보다 작다면
    printf("입력한 수의 합은 %d 입니다.\n", sum);
    return 0;
}