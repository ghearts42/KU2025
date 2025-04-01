#include <stdio.h>
#include <wiringPi.h>

#define LED1 23
#define LED2 24
#define LED3 25
#define LED4 1

int main()
{
    wiringPiSetupGpio(); // BCM 기준의 gpio 핀번호
    pinMode(LED2, OUTPUT);
    while (1)
    {
        digitalWrite(LED2, HIGH);
    }

    printf("Hello World\n");

    return 0;
}