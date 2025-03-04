/* This program is calculating int & float*/
#include <stdio.h>

int main(){
    int celsius;
    //celsius = 15;
    printf("Input Celsius Temp : ");
    scanf("%d", &celsius);
    printf("celsius temp : %d \n", celsius);

    double fahr;
    fahr = 9.0 / 5.0 * celsius + 32;
    printf("fehr temp : %f \n", fahr);
    //float 연산은 왠만하면 float 끼리 한다.
    return 0;
}
