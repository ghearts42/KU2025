#include <stdio.h>

enum season // 가시성이나 옵션에 따라 사용한다........
{
    SPRING = 1, // int > 0,1,2,3...
    SUMMER = 2,
    FALL = 4,
    WINTER = 8
};
// define SPRING 0 ... < 이딴식으로 쓰느니 enum을 쓰는것이 편하다
int main(void)
{
    enum season ss;
    char *pc = NULL;

    ss = SPRING;
    switch (ss) // switch에 들어가는 자료형은 int이므로 enum을 사용한 경우 각 문자열마다에 나열 순서에 따른 번호가 부여됨.
    {
    case SPRING:
        pc = "inline";
        break;

    case SUMMER:
        pc = "swimming";
        break;
    case FALL:
        pc = "trip";
        break;
    case WINTER:
        pc = "skiing";
        break;
    }
    printf("나으 레자 활동 => %s\n", pc);
    printf("%d", SPRING);
    return 0;
}