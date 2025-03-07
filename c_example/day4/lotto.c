// 10개 크기의 배열을 랜덤(0~100)으로 만들고 int를 하나 scanf로 받고 같은 원소가 있는지 프린트

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int lotto[6] = {0};
    int find = 0;
    int number[6] = {0};
    int TF = 0;
    int where = 0;
    printf("자동 번호 : ");
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 6; ++i)
    {
        number[i] = rand() % 46;
        printf("%d ", number[i]);
    }

    for (int j = 0; 1; ++j)
    {
        lotto[j] = rand() % 46;

        if (find == lotto[j])
        {
            TF = 1;
            where = i;
        }
    }
    if (TF >= 1)
    {
        printf("같은 숫자가 %d번 배열에 있습니다!!!!!!!!!!!!!!!!!!!!!!!!!!!!!", where + 1);
    }
    else
    {
        printf("같은 숫자가 배열에 없습니다.");
    }

    return 0;
}