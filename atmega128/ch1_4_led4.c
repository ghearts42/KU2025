
#include "lcd.h"
#include <avr/io.h>
// AVR 입출력에 대한 헤더 파일
#include <util/delay.h> // delay 함수사용을 위한 헤더파일

int main(void)
{

    while (1)
    {
        DDRC = 0x0f; // 1111 0,1을 출력 포트로 설정
        int LED_Data = 1;
        if (LED_Data == 1)
        {
            while (LED_Data < 8)
            {
                LED_Data *= 2;
                PORTC = LED_Data;
                _delay_ms(1000); // 1초 대기
            }
        }
        if (LED_Data == 8)
        {
            while (LED_Data > 1)
            {
                LED_Data /= 2;
                PORTC = LED_Data;
                _delay_ms(1000); // 1초 대기
            }
        }
    }
    return 0;
}
