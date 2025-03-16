#include <stdio.h>
#include <stdlib.h>

#define FRAME 3   // 10 프레임
#define TRY 2      // 한 프레임에 2번 시도
#define PLAYER 2   // 2명의 플레이어

// 점수를 계산하는 함수들
int calculate_base_score(int frame[], int try_count) {
    int total_score = 0;
    for (int i = 0; i < try_count; ++i) {
        total_score += frame[i];
    }
    return total_score;
}

int calculate_spare_bonus(int game[FRAME][TRY][PLAYER], int frame_index, int player_index) {
    if (frame_index + 1 < FRAME) {
        return game[frame_index + 1][0][player_index]; // 스페어는 다음 프레임 첫 번째 시도의 점수를 보너스로 더함
    }
    return 0; // 마지막 프레임은 보너스가 없음
}

int calculate_strike_bonus(int game[FRAME][TRY][PLAYER], int frame_index, int player_index) {
    int bonus = 0;
    if (frame_index + 1 < FRAME) {
        bonus += game[frame_index + 1][0][player_index]; // 스트라이크는 다음 프레임 첫 번째 시도의 점수를 보너스로 더함
        if (frame_index + 1 < FRAME && game[frame_index + 1][0][player_index] == 10) {
            if (frame_index + 2 < FRAME) {
                bonus += game[frame_index + 2][0][player_index]; // 두 번째 시도까지 보너스를 추가
            }
        } else if (frame_index + 1 < FRAME) {
            bonus += game[frame_index + 1][1][player_index]; // 두 번째 시도 점수
        }
    }
    return bonus;
}

int main()
{
    int Score[PLAYER] = {0};     // 각 플레이어의 점수
    int game[FRAME][TRY][PLAYER]; // 게임 점수 기록

    // 게임 진행
    for (int i = 0; i < FRAME; ++i) {
        for (int j = 0; j < PLAYER; ++j) {
            for (int k = 0; k < TRY; ++k) {
                printf("플레이어 %d : %d번 프레임 : %d번째 시도 : ", j + 1, i + 1, k + 1);
                scanf("%d", &game[i][k][j]); // 점수 입력
            }
        }
    }

    // 각 플레이어의 점수 계산
    for (int j = 0; j < PLAYER; ++j) {
        int total_score = 0;

        for (int i = 0; i < FRAME; ++i) {
            int frame_score = calculate_base_score(game[i], TRY); // 기본 점수 계산

            if (frame_score == 10 && game[i][0][j] == 10) { // 스트라이크일 때
                frame_score += calculate_strike_bonus(game, i, j); // 스트라이크 보너스 추가
            } else if (frame_score == 10) { // 스페어일 때
                frame_score += calculate_spare_bonus(game, i, j); // 스페어 보너스 추가
            }

            total_score += frame_score; // 해당 프레임 점수 누적
        }

        Score[j] = total_score; // 최종 점수 저장
    }

    // 최종 점수 출력
    printf("플레이어 1 최종 점수 : %d\n", Score[0]);
    printf("플레이어 2 최종 점수 : %d\n", Score[1]);

    return 0;
}
