#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define TH_ADDR 0x40
#define SHT20_TRIG_REG 0xE3
#define SHT20_RESET 0xFE

int main(void)
{
    int th_fd = wiringPiI2CSetup(TH_ADDR);
    delay(100);

    wiringPiI2CWrite(th_fd, SHT20_RESET);
    delay(100);

    wiringPiI2CWrite(th_fd, SHT20_TRIG_REG);
    delay(100);
    int temp_msb = wiringPiI2CRead(th_fd);
    int temp_lsb = wiringPiI2CRead(th_fd);

    if (temp_msb >= 0 && temp_lsb >= 0)
    {
        int temp_raw = (temp_msb << 8) | (temp_lsb & 0xFC);
        float temperature = -46.85 + 175.72 * (temp_raw / 65535.0);
        printf("온도 : %.2f 센서 정상\n", temperature);
    }
    else
    {
        printf("온도몰라레후");
    }

    wiringPiI2CWrite(th_fd, SHT20_TRIG_REG + 2);
    delay(100);

    int rh_msb = wiringPiI2CRead(th_fd);
    int rh_lsb = wiringPiI2CRead(th_fd);

    if (rh_msb >= 0 && rh_lsb >= 0)
    {
        int rh_raw = (rh_msb << 8) | (rh_lsb & 0xFC);
        float humidity = -6 + 125.0 * (rh_raw / 65535.0);
        printf("습도 : %.2f 센서 정상\n", humidity);
    }
    else
    {
        printf("습도몰라레후");
    }

    return 0;
}