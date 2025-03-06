#include <stdio.h>

int main(){
    double fahr;
    fahr = 59;

    printf("fahr = %f \n", fahr);

    int celsius;
    celsius = (fahr - 32) * 5 / 9;

    printf("celsius = %d \n",celsius);

    return 0;
}