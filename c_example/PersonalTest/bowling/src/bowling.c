#include "bowling.h"

void score_sql(void)
{
    display_scores;
}

void print_menu(void)
{
    system("clear");
    printf("=== 볼  링 ===\n");
    printf("0. 시작\n");
    printf("1. SQL 조회\n");
    printf("2. 종료\n");
}

void waitEnter(void)
{
    printf("엔터입력으로 종료...\n");
    char temp;
    while (temp != '\n')
    {
        scanf("%c%*c", &temp);
    }
}

void frame()
{
    // 기본 점수 입력
    user list[10];
    int game[FRAME][TRY][PLAYER] = {0};
    int FrameScore = 0;

    for (int i = 0; i < PLAYER; ++i)
    {
        printf("플레이어 %d의 이름 입력 : \n", i + 1);
        scanf("%s", list[i].username);
    }

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
}

void scoring()
{
    // 변수선언
    user list[10];
    int game[FRAME][TRY][PLAYER];
    int Score[PLAYER] = {0};
    int Base_Score = 0;
    int Bonus_Score;
    int winner;

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
        insert_score(list[i].username, Score[i]);
    }
    for (int i = 0; i < PLAYER - 1; ++i)
    {
        if (Score[i] == Score[i + 1])
        {
            winner = -1;
        }
        else if (Score[i] < Score[i + 1])
        {
            winner = i + 1;
        }
        else
        {
            winner = i;
        }
    }
    if (winner == -1)
    {
        printf("무승부\n");
    }
    else
    {
        printf("플레이어 %s 승리!\n", list[winner].username);
    }
    for (int i = 0; i < PLAYER; ++i)
    {
        list[i].bowlingScore = Score[i];
        list[i].date = 123;
    }

    score_sql(); // MySQL에서 점수 조회 및 출력
    waitEnter();
}