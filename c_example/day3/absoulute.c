#include <stdio.h>
#include <stdbool.h>

int main(void){

    //숫자 입력
    int num;
    int state;
    printf("숫자 입력 : ");
    scanf("%d", &num);

    //절댓값 처리
    if (num < 0){
        state = false;
    }
    else{
        state = true;
    }
    num = state ? num : -num;
    // 조건 연산자 (조건 ? TRUE : FALSE / 조건이 참이면 TRUE, 거짓이면 FALSE를 반환함)
    //숫자 출력
    printf("입력 숫자의 절댓값 : %d\n", num);

    return 0;
}