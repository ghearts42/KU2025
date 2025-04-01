// 우
// 일석
// 맞죠?

// 시스템 콜에 대한 기본적인 함수

#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define LED1 23
#define LED2 24
#define LED3 25
#define LED4 1
#define SW1 4
#define SW2 17
#define SW3 27
#define SW4 22

int main()
{
    int fd = open("sys/class/gpio/export", O_WRONLY);
    write(fd, "23", strlen("23"));
    close(fd);
    fd = open("/sys/class/gpio/gpio23/direction", O_WRONLY);
    write(fd, "out", strlen("out"));
    close(fd);
    fd = open("/sys/class/gpio/gpio23/value", O_WRONLY);

    for (int i = 0; i < 5; ++i)
    {
        write(fd, "1", strlen("1"));
        sleep(1);
        write(fd, "0", strlen("0"));
        sleep(1);
    }

    close(fd);
    fd = open("/sys/class/gpio/unexport", O_WRONLY);
    write(fd, "23", strlen("23"));
    close(fd);
    return 0;
}