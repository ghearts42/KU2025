// 3*4의 2차원 배열을 만들어 총합을 출력
#include <stdio.h>

int main(void)
{
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {11, 12, 13, 14},
        {21, 22, 23, 24}};
    int sum;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            printf("%d행 %d열 %d\n", i + 1, j + 1, matrix[i][j]);
            sum += matrix[i][j];
        }
    }

    printf("sum: %d\n", sum);
    return 0;
}