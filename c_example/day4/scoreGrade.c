// A ~ F 점수 받아 출력
#include <stdio.h>

int main(void)
{
    char grades[] = {'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A', '\0'};
    char grade = 'F';
    int score;
    while (1)
    {
        printf("점수 : ");
        scanf("%d", &score);
        grade = 'F';

        if (score > 0 && score <= 100)
        {
            grade = grades[score / 10];
        }
        printf("점수는 : %d --- %c\n", score, grade);
    }
    return 0;
}