#include "lcd.h"
#include <avr/io.h>
// AVR 입출력에 대한 헤더 파일
#include <util/delay.h> // delay 함수사용을 위한 헤더파일
#include <stdio.h>

int main(void)
{
    lcdInit();
    lcdClear();
    char lcdBuffer[17];

    unsigned char switch_flag = 0;
    DDRE = 0x00;  // 8개의 핀을 모두 인풋
    PORTE = 0x00; // 출력 - 풀업을 설정.
    DDRC = 0x0f;  // 아웃풋
    // PINE
    while (1)
    {
        if (PINE >> 4) // PIN E
        {
            switch_flag = PINE >> 4; // 0b1000 0b0100
        }
        PORTC = switch_flag;
        snprintf(lcdBuffer, sizeof(lcdBuffer), "SW : 0x%02X, %c", switch_flag, switch_flag);

        lcdGotoXY(0, 0);
        lcdPrint(lcdBuffer);
    }
    return 0;
}
