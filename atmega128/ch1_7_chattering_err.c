#include "lcd.h"
#include <stdio.h>
#include <string.h>
#include <avr/io.h>     // AVR 입출력에 대한 헤더 파일
#include <util/delay.h> // delay 함수사용을 위한 헤더파일

int main(void)
{

    unsigned char switchFlag = 0;
    DDRC = 0x0F;
    PORTE = 0x00; // 풀 업 설 정

    lcdInit();
    lcdClear();
    char lcdBuffer[17];

    while (1)
    {
        if (PINE >> 2)
        {
            switchFlag = PINE >> 2;
        }
        if (!switchFlag)
        {
            PORTC ^= 0x01; // 1번 비트 반전 XOR 연산
        }
        lcdGotoXY(0, 0);
        lcdBuffer[17] = "";
        sprintf(lcdBuffer, "%d", switchFlag);
        lcdPrint(lcdBuffer);
        // PORTC ^= 0x01; // 1번 비트 반전 XOR 연산 00,11 > 0 01,10 > 1
        // _delay_ms(1000);
    }

    return 0;
}
