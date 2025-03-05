// 두 숫자를 받아 크기 관계 0과 1로 프린트 하기

#include <stdio.h>

int main(void){
    int a, b;
    int greater;
    printf("두 정수 입력 : ");
    scanf("%d %d", &a, &b);

    greater = a > b;
    printf("greater의 값 : %d\n", greater);

    return 0;
}