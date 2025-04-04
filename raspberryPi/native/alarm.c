#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <softPwm.h>
#include <softTone.h>

#define GYRO_ADDR 0x68

// 자이로 센서 레지스트리
#define PWR_MGMT_1 0x6B
#define GYRO_CONFIG 0x1B
#define ACCEL_CONFIG 0x1C
#define ACCEL_XOUT_H 0x3B
#define GYRO_XOUT_H 0x43

// LED 레지스트리
#define RGB_SERVO_I2C_ADDR 0x5e
#define PCA9685_LED_ON_L 0x06
#define PCA9685_PRESCALE 0xFE
#define PCA9685_MODE1 0x00

// 부저 레지스트리
#define BUZZER_PIN 26

void setPWMFrequency(int freq);
void i2C_init(int fd, int freq);

int main(void)
{
    wiringPiSetup(); // BCM 기준의 gpio 핀번호
    pinMode(BUZZER_PIN, PWM_OUTPUT);
    softToneCreate(BUZZER_PIN);

    // MPU 6050 초기화
    int gyro_fd = wiringPiI2CSetup(GYRO_ADDR);
    delay(100);

    wiringPiI2CWriteReg8(gyro_fd, PWR_MGMT_1, 0x00);
    wiringPiI2CWriteReg8(gyro_fd, GYRO_CONFIG, 0x00);
    wiringPiI2CWriteReg8(gyro_fd, ACCEL_CONFIG, 0x00);
    delay(100);

    const int samples = 100;

    int rgb_servo_fd = wiringPiI2CSetup(RGB_SERVO_I2C_ADDR);
    i2C_init(rgb_servo_fd, 0x79); // 50hz

    int16_t accel_x_offset = 0, accel_y_offset = 0, accel_z_offset = 0;
    int16_t gyro_x_offset = 0, gyro_y_offset = 0, gyro_z_offset = 0;

    for (int i = 0; i < samples; i++)
    {
        int16_t ax = wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H) << 8 | wiringPiI2CReadReg16(gyro_fd, ACCEL_XOUT_H + 1);
        int16_t ay = wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 2) << 8 | wiringPiI2CReadReg16(gyro_fd, ACCEL_XOUT_H + 3);
        int16_t az = wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 4) << 8 | wiringPiI2CReadReg16(gyro_fd, ACCEL_XOUT_H + 5);
        int16_t gx = wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H) << 8 | wiringPiI2CReadReg16(gyro_fd, GYRO_XOUT_H + 1);
        int16_t gy = wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 2) << 8 | wiringPiI2CReadReg16(gyro_fd, GYRO_XOUT_H + 3);
        int16_t gz = wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 4) << 8 | wiringPiI2CReadReg16(gyro_fd, GYRO_XOUT_H + 5);

        accel_x_offset += ax;
        accel_y_offset += ay;
        accel_z_offset += az;

        gyro_x_offset += gx;
        gyro_y_offset += gy;
        gyro_z_offset += gz;
        delay(10);
    }

    accel_x_offset /= 100 * 16384.0;
    accel_y_offset /= 100 * 16384.0;
    accel_z_offset /= 100 * 16384.0;
    gyro_x_offset /= 100 * 131.0;
    gyro_y_offset /= 100 * 131.0;
    gyro_z_offset /= 100 * 131.0;

    while (1)
    {
        int16_t ax = wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H) << 8 | wiringPiI2CReadReg16(gyro_fd, ACCEL_XOUT_H + 1);
        int16_t ay = wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 2) << 8 | wiringPiI2CReadReg16(gyro_fd, ACCEL_XOUT_H + 3);
        int16_t az = wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 4) << 8 | wiringPiI2CReadReg16(gyro_fd, ACCEL_XOUT_H + 5);
        int16_t gx = wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H) << 8 | wiringPiI2CReadReg16(gyro_fd, GYRO_XOUT_H + 1);
        int16_t gy = wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 2) << 8 | wiringPiI2CReadReg16(gyro_fd, GYRO_XOUT_H + 3);
        int16_t gz = wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 4) << 8 | wiringPiI2CReadReg16(gyro_fd, GYRO_XOUT_H + 5);
        printf("ax : %f\n", (float)ax / 16384.0 - accel_x_offset);
        printf("ay : %f\n", (float)ay / 16384.0 - accel_y_offset);
        printf("az : %f\n", (float)az / 16384.0 - accel_z_offset);
        printf("gx : %f\n", (float)gx / 131.0 - gyro_x_offset);
        printf("gy : %f\n", (float)gy / 131.0 - gyro_y_offset);
        printf("gz : %f\n", (float)gz / 131.0 - gyro_z_offset);
        if (-5 > ((float)gy / 131.0 - gyro_y_offset) || ((float)gy / 131.0 - gyro_y_offset) > 5)
        {
            wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 2, 4095);
            setPWMFrequency(523);
            pwmWrite(BUZZER_PIN, 1000);
            softToneWrite(BUZZER_PIN, 523);
            // softPwmWrite(LED4, i);
        }
        delay(100);
    }

    return 0;
}

void i2C_init(int fd, int freq)
{
    wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0x01);    // 리셋
    delay(10);                                        // 리셋 후 대기
    wiringPiI2CWriteReg8(fd, PCA9685_PRESCALE, freq); // 주파수 60Hz 설정
    wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0xA1);
}

void setPWMFrequency(int freq)
{
    int range = 2000;
    int clock = 19200000 / (range * freq);
    pwmSetMode(PWM_MODE_MS);
    pwmSetRange(range);
    pwmSetClock(clock);
}