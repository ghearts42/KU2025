#include <stdio.h>
#include <stdbool.h>

int main(void)
{

    int year;

    while (true)
    {
        printf("년도 입력 : ");
        scanf("%d", &year);

        // if(year % 4 == 0)
        // {
        //     printf("%d 년도는 윤년입니다.\n", year);
        // }
        // else
        // {
        //     printf("%d 년도는 평년입니다.\n", year);
        // }

        printf("%d 년도는 %s입니다.\n", year, year % 4 ? "평년" : "윤년");

        if (!year)
            break;
        // if(year == 0) //if문의 블럭이 단 한줄일 경우 괄호를 붙이지 않아도 된다.
    }
}