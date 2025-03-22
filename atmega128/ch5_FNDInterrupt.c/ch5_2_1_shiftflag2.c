#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t shiftFlag = 1;

int main()
{
    uint8_t ledData = 0x01;

    DDRC = 0x0F; // 하위 비트 4개 출력

    EIMSK = _BV(INT4) | _BV(INT6); // 0b01010000 INT4,6

    // EICRB = 0xC8; // 0b11001000 인터럽트 5는 하강, 7는 상승
    EICRB = _BV(ISC60) | _BV(ISC40); // 40,60 하강엣지 = 눌렸을 때 발동 41,61 상승엣지 = 스위치가 떼어졌을 때 발동
    EIFR = 0x50;                     // 플래그 클리어
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

ISR(INT4_vect)
{
    cli();
    shiftFlag = 1;
    sei();
}

ISR(INT6_vect)
{
    cli();
    shiftFlag = 2;
    sei();
}