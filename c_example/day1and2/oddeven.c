// 홀짝 구분하기
#include <stdio.h>

int main(void){
    int num;
    printf("숫자 : ");
    scanf("%d", &num);

    int isOdd;
    isOdd = (num % 2);

    printf("num %d \t isOdd : %d\n", num, isOdd);
    return 0;
}