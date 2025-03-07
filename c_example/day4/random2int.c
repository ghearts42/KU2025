// 운빨게임
// 두 개의 int를 랜덤으로 같은 수가 나올 때까지 출력함
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(void)
{
    int a, b;
    double rand1, rand2;
    int i;
    while (true)
    {
        i++;
        srand((unsigned int)time(NULL) + i); // random 세팅
        rand1 = rand() / (double)RAND_MAX * 100000;
        // srand((unsigned int)time(NULL) + i + i);
        rand2 = rand() / (double)RAND_MAX * 100000;

        a = rand1;
        b = rand2;

        printf("1. 0 ~ 100 사이의 값 : %d\n", a);
        printf("2. 0 ~ 100 사이의 값 : %d\n", b);
        printf("%d > %d : %s\n", (int)a, (int)b, (int)a > (int)b ? "참" : "거짓");
        printf("%d < %d : %s\n", (int)a, (int)b, (int)a < (int)b ? "참" : "거짓");
        printf("%d == %d : %s\n", (int)a, (int)b, (int)a == (int)b ? "참" : "거짓");
        printf("%d != %d : %s\n", (int)a, (int)b, (int)a != (int)b ? "참" : "거짓");

        if (a == b)
        {
            break;
        }
    }
    return 0;
}