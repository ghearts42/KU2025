// 점수 출력 코드 A ~ F
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int score;
    if (argc < 2)
    {
        printf("인자를 넣어라.\n");
        return 0;
    }
    score = atoi(argv[1]);

    switch (score / 10)
    {
    case 10:
    case 9:
        printf("SCORE : %d === A\n", score);
        break;

    case 8:
        printf("SCORE : %d === B\n", score);
        break;

    case 7:
        printf("SCORE : %d === C\n", score);
        break;

    case 6:
        printf("SCORE : %d === D\n", score);
        break;

    default:
        printf("SCORE : %d === F\n", score);
        break;
    }
    return 0;
}