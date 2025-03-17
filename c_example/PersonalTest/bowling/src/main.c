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

#include "bowling.h"

int main()
{
    // 변수선언

    int choice;
    user list[10];
    int Score[PLAYER] = {0};
    int game[FRAME][TRY][PLAYER] = {0};
    int FrameScore = 0;
    int Base_Score = 0;
    int Bonus_Score;
    MYSQL *conn;

    enum menu
    {
        START,
        SQL,
        QUIT
    };
    // 프로그램 시작
    conn = mysql_init(NULL);
    connect_to_db();
    printf("테이블 생성 중...\n");
    // create_table(conn);

    while (1)
    {
        print_menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case START:
            // 기본 점수 입력
            frame(game[FRAME][TRY][PLAYER]);
            // Base 점수 계산
            scoring(game[FRAME][TRY][PLAYER]);
            waitEnter();
            break;

        case SQL:
            display_scores();
            waitEnter();
            break;
        case QUIT:
            printf("프로그램 종료...\n");
            exit(0);
        }
    }
    return 0;
}