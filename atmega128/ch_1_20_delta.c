// timer2 번을 써서 LED 좌우로 움직이는 코드 작성. 0.3초마다 움직이기.
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

uint8_t ledData = 0x01;
volatile uint8_t timer2Cnt = 0;
ISR(TIMER2_OVF_vect);

int main(void)
{
    DDRC = 0x00;
    DDRB |= _BV(PB4);

    TCCR0 = _BV(CS01) | _BV(WGM00)| _BV(WGM01)| _BV(COM01); // clock select 1024 prescale

    uint8_t brightness = 0;
    int8_t delta = 1;

    while (1)
    {
        OCR0 = brightness; //0~255
        _delay_ms(10);
        brightness += delta;
        if (brightness == 0 || brightness == 255)
        {
            delta = -delta;
        }
    }
    return 0;
}