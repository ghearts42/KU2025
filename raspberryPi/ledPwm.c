#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define LED1 23
#define LED2 24
#define LED3 25
#define LED4 1
#define BUZZER_PIN 12

int CDE[8] = {523, 587, 659, 698, 783, 880, 987, 1046};

int main()
{
    wiringPiSetupGpio(); // BCM 기준의 gpio 핀번호
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    softToneCreate(BUZZER_PIN);
    // softPwmCreate(LED1, 255, 255);
    // softPwmCreate(LED2, 120, 255);
    // softPwmCreate(LED3, 0, 255);
    // softPwmCreate(LED4, 0, 255);
    while (1)
    {
        for (int i = 0; i < 8; ++i)
        {
            softToneWrite(BUZZER_PIN, CDE[i]);
            // softPwmWrite(LED4, i);
            delay(100);
        }
    }

    return 0;
}