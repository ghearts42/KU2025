// 10개 크기의 배열을 랜덤(0~100)으로 만들고 int를 하나 scanf로 받고 같은 원소가 있는지 프린트

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int arr[10] = {0};
    int find = 0;
    int TF = 0;
    int where = 0;
    printf("숫자 입력 : ");
    scanf("%d", &find);
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 10; ++i)
    {
        arr[i] = rand() % 101;
        printf("%d번 숫자 : %d \n", i + 1, arr[i]);

        if (find == arr[i])
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
    return 1;
}