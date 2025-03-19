#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t shiftFlag = 1;

int main()
{
    uint8_t ledData = 0x01;

    DDRC = 0x0F; // 하위 비트 4개 출력

    EIMSK = 0xA0; // 0b10100000 INT5, INT7

    EICRB = 0xC8; // 0b11001000 인터럽트 5는 하강, 7는 상승
    // EICRB = _BV(ISC71) | _BV(ISC70) | _BV(ISC51);
    EIFR = 0xA0; // 플래그 클리어
    sei();

    while (1)
    {
        PORTC = ledData;
        if (shiftFlag == 1)
        {
            if (ledData == 0x08)
            {
                ledData = 0x01;
            }
            else
            {
                ledData <<= 1;
            }
        }
        else if (shiftFlag == 2)
        {
            if (ledData == 0x01)
            {
                ledData = 0x08;
            }
            else
            {
                ledData >>= 1;
            }
        }
        _delay_ms(200);
    }
    return 0;
}

ISR(INT5_vect)
{
    cli();
    shiftFlag = 1;
    sei();
}

ISR(INT7_vect)
{
    cli();
    shiftFlag = 2;
    sei();
}