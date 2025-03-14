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

#define FRAME 3
#define TRY 2
#define PLAYER 2

int frame()
{
    int Score[PLAYER] = {0};
    int game[TRY][FRAME][PLAYER];
    int P_Score = 0;

    for (int i = 0; i < FRAME; ++i)
    {
        for (int j = 0; j < PLAYER; ++j)
        {
            for (int k = 0; k < TRY; ++k)
            {
                printf("플레이어 %d : %d번 프레임 : %d번째 시도 : ", j + 1, i + 1, k + 1);
                scanf("%d", &game[i][j][k]);

                P_Score += game[i][j][k];

                // Score[j] += game[i][j][k];
            }
        }
    }

    printf("플레이어 1 최종 점수 : %d\n", Score[0]);
    printf("플레이어 1 최종 점수 : %d\n", Score[1]);

    return 0;
}