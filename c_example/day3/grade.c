// 점수 출력 코드 A ~ F
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int score;
    if (argc < 2)
    {
        printf("인자를 넣어라.\n");
        return 0;
    }
    score = atoi(argv[1]);

    if (score >= 90)
    {
        printf("SCORE : %d === A\n",score);
    }
    else if (score >= 80)
    {
        printf("SCORE : %d === B\n",score);
    }
    else if (score >= 70)
    {
        printf("SCORE : %d === C\n",score);
    }
    else if (score >= 60)
    {
        printf("SCORE : %d === D\n",score);
    }
    else
    {
        printf("SCORE : %d === F\n",score);
    }
    return 0;
}