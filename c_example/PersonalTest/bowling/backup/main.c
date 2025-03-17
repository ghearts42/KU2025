// 볼링 프로그램 만들기
// 1.    입력 함수 FRAME
//       여러명이 동시 사용 가능
//       2번 쳐서 10점 내면 스페어
//       1번 쳐서 10점 이면 스트라이크 (아무튼 볼링 룰대로)

// 2.    사용자명 점수 날짜 1번 테이블로
//       사용자명 날짜별 횟수 2번 테이블

// 볼링 룰 (300점)
// 1. 10개의 프레임 / 프레임 당 2번의 기회가 주어짐
// 2. 볼링 핀은 10개
// 3. 핀을 전부 처리하지 못하면 '오픈'
// 4. 핀을 2번만에 모두 처리하면 '스페어'
// 	4-1 스페어 처리시 그 다음 프레임의 첫번째 공이 친 점수가 보너스로 더해짐(1프레임 7점, 2프레임 스페어, 3프레임에 7/3이면 2프레임 점수 = 7 + 10 + 3 = 20

// 5. 핀을 한번에 모두 처리하면 '스트라이크'
// 	5-1 스트라이크 시 그 다음 프레임의 점수를 점수에 추가함
// 6. 스트라이크가 두번 연속이면 '더블', 세번이면 '터키'
// 7. 공이 홈으로 빠져 아무것도 치지 못하면 '거터' -

#include <stdio.h>
#include <stdlib.h>

#define FRAME 11
#define TRY 2
#define PLAYER 2

int main()
{
    // 변수선언

    int Score[PLAYER] = {0};
    int game[FRAME][TRY][PLAYER];
    int FrameScore = 0;
    int Base_Score;
    int Bonus_Score;

    // 기본 점수 입력

    for (int i = 0; i < FRAME - 1; ++i)
    {
        for (int j = 0; j < PLAYER; ++j)
        {
            for (int k = 0; k < TRY; ++k)
            {
                printf("플레이어 %d : %d번 프레임 : %d번째 시도 : ", j + 1, i + 1, k + 1);
                scanf("%d", &game[i][k][j]);
                FrameScore += game[i][k][j];
                if (game[i][0][j] == 10)
                {
                    printf("STRIKE\n");
                    game[i][1][j] = 0;
                    k += 1;
                }
                else if (FrameScore == 10)
                {
                    printf("SPARE\n");
                }
                else if (FrameScore > 10)
                {
                    printf("10점을 넘을 수 없습니다\n");
                    FrameScore -= game[i][k][j];
                    k -= 1;
                    continue;
                }
            }
            FrameScore = 0;
        }
    }

    // 마지막 프레임에서 스트라이크 혹은 스페어가 났을 때의 추가 프레임

    for (int i = 0; i < PLAYER; ++i)
    {
        if (game[FRAME - 2][0][i] == 10)
        {
            printf("last frame(strike)\n");
            for (int j = 0; j < TRY; ++j)
            {
                printf("플레이어 %d : 보너스 프레임 : %d번째 시도 : ", i + 1, j + 1);
                scanf("%d", &game[FRAME - 1][j][i]);
                if (game[FRAME - 1][j][i] > 10)
                {
                    printf("over 10\n");
                    j -= 1;
                    continue;
                }
            }
        }
        else if (game[FRAME - 2][0][i] + game[FRAME - 2][1][i] == 10)
        {
            printf("last try(spare)\n");
            do
            {
                printf("플레이어 %d : 보너스 프레임 : last 시도 : ", i + 1);
                scanf("%d", &game[FRAME - 1][0][i]);
                if (game[FRAME - 1][0][i] > 10)
                {
                    printf("over 10\n");
                }
            } while (game[FRAME - 1][0][i] > 10);
            game[FRAME - 1][1][i] = 0;
        }
    }

    // Base 점수 계산

    for (int i = 0; i < PLAYER; ++i)
    {
        Base_Score = 0;
        for (int j = 0; j < FRAME - 1; ++j)
        {
            for (int k = 0; k < TRY; ++k)
            {
                Base_Score += game[j][k][i];
            }
        }
        // printf("Base : %d\n", Base_Score);
        Score[i] += Base_Score;
    }

    // Bonus 점수 계산

    for (int i = 0; i < PLAYER; ++i)
    {
        Bonus_Score = 0;
        for (int j = 0; j < FRAME - 1; ++j)
        {
            if (game[j][0][i] == 10 && j + 1 < FRAME)
            {
                if (game[j + 1][0][i] == 10 && j + 2 < FRAME)
                {
                    Bonus_Score += game[j + 1][0][i] + game[j + 2][0][i];
                    // printf("D Strike : %d", Bonus_Score);
                }
                else
                {
                    Bonus_Score += game[j + 1][0][i] + game[j + 1][1][i];
                    // printf("Else : %d", Bonus_Score);
                }
            }
            else if (game[j][0][i] + game[j][1][i] == 10)
            {
                Bonus_Score += game[j + 1][0][i];
                // printf("Base : %d", Bonus_Score);
            }
        }
        // printf("Bonus : %d\n", Bonus_Score);
        Score[i] += Bonus_Score;
    }

    for (int i = 0; i < PLAYER; ++i)
    {
        printf("플레이어 %d 최종 점수 : %d\n", i + 1, Score[i]);
    }

    return 0;
}