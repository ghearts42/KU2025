#include <avr/io.h>
// AVR 입출력에 대한 헤더 파일
#include <util/delay.h> // delay 함수사용을 위한 헤더파일

int main(void)
{
    unsigned char LED_Data;
    LED_Data = 0x01;
    int direction = 0;
    while (1)
    {
        while (1)
        {
            if (LED_Data >= 0x0F)
            {
                direction = 0;
            }
            if (LED_Data == 0)
            {
                direction = 1;
                LED_Data = 1;
            }

            if (direction)
            {
                LED_Data >>= 1;
            }
            else
            {
                LED_Data <<= 1;
            }
            PORTC = LED_Data;
            _delay_ms(500);
        }
    }
    return 0;
}
