#include <stdio.h>
#include <unistd.h>

int main(void)
{
    // 버퍼를 비우는 기능이 없어 fflush를 쓰지 않으면 한번에 세번나옴
    sleep(1);
    printf("우\n");
    fflush(stdout);
    sleep(1);
    printf("일석\n");
    fflush(stdout);
    sleep(1);
    printf("맞죠?\n");
    fflush(stdout);
    sleep(1);
    return 0;
}