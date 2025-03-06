// 1과 9 사이의 숫자인지 확인해서 맞으면 1 틀리면 0을 프린트

#include <stdio.h>

int main(void){
    //변수 선언
    int a, b;
    
    //숫자 입력
    printf("입력 : ");
    scanf("%d", &a);
    
    b = a <= 9 && a >= 1;
    
    printf ("1 <= %d <= 9 : %d \n", a, b);
    
    return 0;
}