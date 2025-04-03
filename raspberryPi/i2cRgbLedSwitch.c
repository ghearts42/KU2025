// 스위치 1 > R, 2 > G, 3 > B 색 변화 하게
// 오래 누르면 높은 값으로 변화하게

#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define RGB_SERVO_I2C_ADDR 0x5e
#define PCA9685_LED_ON_L 0x06
#define PCA9685_PRESCALE 0xFE
#define PCA9685_MODE1 0x00

#define SW1 4
#define SW2 17
#define SW3 27

void SW_ISR1R(void);
void SW_ISR2R(void);
void SW_ISR3R(void);

void i2C_init(int fd, int freq);

int r_value, g_value, b_value;
int rStartTime, gStartTime, bStartTime;
int rPushed, gPushed, bPushed;

int main(void)
{

    int rgb_servo_fd = wiringPiI2CSetup(RGB_SERVO_I2C_ADDR);
    i2C_init(rgb_servo_fd, 0x79); // 50hz

    int sw[3] = {SW1, SW2, SW3};

    wiringPiISR(SW1, INT_EDGE_BOTH, SW_ISR1R);
    wiringPiISR(SW2, INT_EDGE_BOTH, SW_ISR2R);
    wiringPiISR(SW3, INT_EDGE_BOTH, SW_ISR3R);

    for (int i = 0; i < 3; ++i)
    {
        pinMode(sw[i], INPUT);
    }

    while (1)
    {
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 2, r_value);
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 6, g_value);
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 10, b_value);
    }

    return 0;
}

void i2C_init(int fd, int freq)
{
    wiringPiSetupGpio();                              // BCM 기준 gpio 핀번호
    wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0x01);    // 리셋
    delay(10);                                        // 리셋 후 대기
    wiringPiI2CWriteReg8(fd, PCA9685_PRESCALE, freq); // 주파수 60Hz 설정
    wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0xA1);

    wiringPiI2CWriteReg16(fd, PCA9685_LED_ON_L, 0);     // 빨
    wiringPiI2CWriteReg16(fd, PCA9685_LED_ON_L + 4, 0); // 녹
    wiringPiI2CWriteReg16(fd, PCA9685_LED_ON_L + 8, 0); // 파
}

void SW_ISR1R(void)
{
    if (!rPushed)
    {
        rStartTime = millis();
        rPushed = 1;
    }
    else
    {
        unsigned int pressTime = millis() - rStartTime;
        r_value = (pressTime * 4095 / 1000);
        if (r_value >= 4096)
        {
            r_value = 4095;
        }
        printf("R : %d", r_value);
        rPushed = 0;
    }
}

void SW_ISR2R(void)
{
    if (!gPushed)
    {
        gStartTime = millis();
        gPushed = 1;
    }
    else
    {
        unsigned int pressTime = millis() - gStartTime;
        g_value = (pressTime * 4095 / 1000);
        if (g_value >= 4096)
        {
            g_value = 4095;
        }
        printf("G : %d", g_value);
        gPushed = 0;
    }
}

void SW_ISR3R(void)
{
    if (!bPushed)
    {
        bStartTime = millis();
        bPushed = 1;
    }
    else
    {
        unsigned int pressTime = millis() - bStartTime;
        b_value = (pressTime * 4095 / 1000);
        if (b_value >= 4096)
        {
            b_value = 4095;
        }
        printf("B : %d", b_value);
        bPushed = 0;
    }
}