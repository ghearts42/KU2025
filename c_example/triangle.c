#include <stdio.h>

int main(void){

    double length;
    double height;
    double area;

    printf("삼각형의 밑변 입력 : ");
    scanf("%lf",&length);
    printf("삼각형의 높이 : ");
    scanf("%lf",&height);
    area = length * height / 2.0;
    printf("삼각형 넓이 : %.2lf \n", area);

    return 0;
}