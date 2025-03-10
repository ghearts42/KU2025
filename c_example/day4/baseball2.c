// 숫자 3개를 만드시오 (단, 서로 다른 숫자 & 랜덤)
// 숫자 3개를 입력 받으세요 (scanf)
// 위치와 숫자가 같으면 strike + 1
// 위치가 다르지만 숫자가 같으면 ball + 1
// 모든 데이터의 위치와 숫자가 동일하면 성공
// 시도 횟수를 출력하는 프로그램을 만드세요.
// 숫자 범위는 0~9

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
    int threeNumbers[3];
    int yourNumbers[3];
    int strike = 0;
    int ball = 0;
    int out = 0;

    //  ✅ 1. 중복되지 않는 난수 생성
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 3; ++i)
    {
        int num;             // 중복검사를 위한 변수
        int duplication = 0; // 중복검사를 위한 조건

        do
        {
            printf("test");
            num = rand() % 10; // 0~9 사이의 난수 생성
            for (int j = 0; j < i; ++j)
            { // 중복검사를 위해 2중 for문
                if (threeNumbers[j] == num)
                {                    // num에 입력된 기생성된 난수와 신규 생성 난수가 중복되어있는지 검사
                    duplication = 1; // 중복되면 거짓으로 do 반복 실행
                    break;
                }
            }
        } while (duplication); // 중복 검사 통과하면
        threeNumbers[i] = num; // 배열에 생성된 난수 입력
    }

    //  ✅ 2. 게임 시작 메세지 출력
    printf("-----------------------------------\n");
    printf("      🔥Baseball Game Start🔥\n");
    printf("-----------------------------------\n");
    fflush(stdout);
    sleep(2);
    printf("   진행하시려면 엔터를 누르세요\n");
    printf("-----------------------------------\n");
    getchar();
    printf("컴퓨터가 생성한 숫자는\n\n"); // 나중에 주석처리
    for (int i = 0; i < 3; i++)
    {
        printf("%d 입니다.\n\n", threeNumbers[i]);
    }

    int attempts = 0; // 시도횟수 카운팅을 위한 변수

    //  ✅ 3. 사용자에게 숫자 입력 받기
    do
    {
        strike = 0; // 숫자 3개 새롭게 입력 받으면 다시 카운팅 해야하므로 0 으로 초기화
        ball = 0;
        out = 0;

        printf("-----------------------------------\n");
        printf("  0~9 사이의 숫자 3개를 입력하세요\n");
        printf("-----------------------------------\n");
        printf(": ");

        for (int i = 0; i < 3; ++i) // 입력 3개 받아야하므로 for문으로 반복
        {
            int num;         // 중복 대조를 위해 값을 대신 받는 변수
            int duplication; // 중복 체크를 위한 변수
            do
            {
                duplication = 0;   // 중복 체크를 위해 0으로 초기화
                scanf("%d", &num); // 숫자 일단 입력받아서 num에 입력
                for (int j = 0; j < i; ++j)
                {
                    if (yourNumbers[j] == num)
                    {                                                     // num 데이터가 배열에 중복되는지 체크해서 조건화
                        printf("\n중복되지 않은 숫자를 넣어주세요!\n\n"); // 한번만 출력되게 하려면 어떻게해야하지??????????
                        duplication = 1;                                  // 중복되면 변수값 1으로 do 문 반복
                        break;
                    }
                }
            } while (duplication); // 중복되지 않았을 때 do 탈출
            yourNumbers[i] = num;
        }

        for (int i = 0; i < 3; i++)
        {
            if (threeNumbers[i] == yourNumbers[i])
            {
                strike++;
            }
            else
            {
                int found = 0;
                for (int j = 0; j < 3; j++)
                {
                    if (threeNumbers[i] == yourNumbers[j])
                    {
                        ball++;
                        found = 1;
                        break;
                    }
                }
            }
        }
        if (strike == 0 && ball == 0)
        {
            printf("-----------------------------------\n");
            printf("   ❌❌❌❌❌❌ OUT ❌❌❌❌❌❌\n");
        }
        printf("-----------------------------------\n");

        attempts++;
        printf("-----------------------------------\n");
        printf("         %d 번째 시도입니다!\n", attempts);
        printf("-----------------------------------\n");
        printf("-----------------------------------\n");
        printf("\nstrike : %d\n", strike);
        printf("\nball : %d\n\n", ball);
        printf("-----------------------------------\n");
    } while (strike < 3);

    return 0;
}
