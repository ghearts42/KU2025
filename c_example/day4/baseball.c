// 숫자 3개를 무작위로 만드시오 (각 숫자는 다 달라야 함)
// 숫자 3개를 입력 받으시오
// 위치와 숫자가 같으면 strike + 1
// 위치가 다르지만 숫자가 같으면 ball + 1
// 모든 데이터 위치와 숫자가 같으면 성공
// 시도 횟수를 출력하는 프로그램을 만드시오

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand((unsigned int)time(NULL));
    int ball[3] = {0};
    do
    {
        for (int i = 0; i < 3; ++i)
        {
            ball[i] = rand() % 10;
            printf("%d번 숫자 : %d\n", i + 1, ball[i]);
        }
    } while (ball[1] == ball[2] || ball[2] == ball[3] || ball[1] == ball[3]);

    int myball[3] = {0};
    printf("무작위 숫자가 주어졌습니다.\n숫자를 입력 : ");
    for (int j = 0; j < 3; ++j)
    {
        scanf("%d", &myball[j]);
        printf("입력한 숫자 %d : %d\n", j, myball[j]);
    }

    // 입력 숫자 판단하여 스트라이크 볼 출력
    int game_strike = 0;
    int game_ball = 0;
    for (int k = 0; k < 3; ++k)
    {
        for (int l = 0; l < 3; ++l)
        {
            if (ball[k] == myball[l])
            {
                if (k == l)
                {
                    game_strike += 1;
                }
                else
                {
                    game_ball += 1;
                }
            }
        }
    }
    if (game_strike == 3)
    {
        printf("승리!");
    }
    else
    {
        printf("%d 스트라이크 %d 볼", game_strike, game_ball);
    }
}