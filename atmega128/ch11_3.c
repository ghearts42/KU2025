#include "lcd.h"
#include <util/delay.h>
#include <avr/io.h>

int main(void)
{
    uint8_t pwmDuty = 60;
    uint8_t cntDir = 0;

    DDRD = _BV(PD4) | _BV(PD5); // M1 출력 설정
    DDRB = _BV(PB5);            // M1 enable

    TCCR1A = _BV(COM1A1) | _BV(WGM11);
    TCCR1B = _BV(CS11) | _BV(WGM12) | _BV(WGM13);

    ICR1 = 800;
    OCR1A = 8 * pwmDuty; // 800을 카운트하되 560번까지 > 5V 70%

    lcdInit();
    lcdGotoXY(0, 0);
    lcdPrintData(" Duty : ", 7);

    PORTD |= _BV(PD4); // M1 정회전
    PORTB |= _BV(PB5); // M1 회전

    while (1)
    {
        if (cntDir)
        {
            pwmDuty = pwmDuty - 5;
            if (pwmDuty < 50)
                cntDir = 0;
        }
        else
        {
            pwmDuty = pwmDuty + 5;
            if (pwmDuty > 99)
                cntDir = 1;
        }
        OCR1A = 8 * pwmDuty; // 0~100
        lcdGotoXY(7, 0);
        lcdDataWrite((pwmDuty / 10) % 10 + '0');
        lcdDataWrite(pwmDuty % 10 + '0');
        lcdDataWrite('%');
    }

    return 0;
}