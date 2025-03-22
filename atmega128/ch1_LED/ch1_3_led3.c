#include <avr/io.h>
// AVR 입출력에 대한 헤더 파일
#include <util/delay.h> // delay 함수사용을 위한 헤더파일

int main(void)
{
    while (1)
    {
        unsigned char LED_Data = 0x00;
        DDRC = 0x0F;
        while (1)
        {
            PORTC = LED_Data;
            LED_Data++;
            if (LED_Data > 0x0F)
            {
                LED_Data = 0;
            }
            _delay_ms(500);
        }
    }
    return 0;
}
