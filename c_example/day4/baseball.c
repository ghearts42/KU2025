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
    srand((unsigned int)time(NULL)); // 랜덤한 숫자를 불러 오기 위해 난수를 생성하는 함수

    int RandomNumber[3] = {0}; // 무작위 숫자를 부여받는 배열
    int myball[3] = {0};       //
    int game_strike = 0;
    int game_ball = 0;

    // RandomNumber에 무작위 숫자를 부여하는 함수
    //  do while을 사용하여 같은 값이 2개 이상이라면 다시 숫자를 부여함
    do
    {
        for (int i = 0; i < 3; ++i)
        {
            RandomNumber[i] = rand() % 10;
            // printf("%d번째 숫자 : %d\n", i + 1, RandomNumber[i]); //무작위 숫자가 겹치는지 테스트하기위한 코드입니다.
        }
    } while (RandomNumber[0] == RandomNumber[1] || RandomNumber[1] == RandomNumber[2] || RandomNumber[0] == RandomNumber[2]);
    printf("0에서 9 사이의 무작위 숫자가 주어졌습니다.\n");

    // 입력 숫자 판단하여 스트라이크 볼 출력하는 함수
    while (1) // While을 사용하여 3스트라이크가 나오지 않는 경우 다시 숫자를 입력함
    {
        printf("숫자를 입력 : ");
        for (int j = 0; j < 3; ++j)
        {
            scanf("%d", &myball[j]);
            printf("%d번째 입력한 숫자 : %d\n", j + 1, myball[j]);
        }
        for (int k = 0; k < 3; ++k)
        {
            for (int l = 0; l < 3; ++l)
            {
                if (RandomNumber[k] == myball[l])
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
            printf("승리!\n");
            break; // 3스트라이크인 경우 승리 출력 후 게임 종료
        }
        else
        {
            printf("=================\n게임 결과\n%d 스트라이크 %d 볼\n=================\n다시 해봅시다.\n=================\n", game_strike, game_ball);
            game_strike = 0;
            game_ball = 0; // 스트라이크가 3개 미만인 경우 다시 시작
        }
    }
}