#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t timer2Cnt = 0;
uint8_t LED_Data = 0x01;

ISR(TIMER2_OVF_vect);

int main(void)
{
    DDRC = 0x0f; // 1111 0,1을 출력 포트로 설정
    TCCR2 = _BV(CS22) | _BV(CS20);
    // TCNT2 = _BV(CS22) | _BV(CS21) | _BV(CS20);
    // TCNT0 = 112;

    TIMSK |= _BV(TOIE2);
    // TIFR |= _BV(TOV0);
    uint8_t direction = 0;
    sei();

    while (1)
    {
        if (timer2Cnt == 30)
        {
            if (LED_Data > 0x04)
            {
                direction = 0;
            }
            if (LED_Data == 1)
            {
                direction = 1;
            }
            if (direction)
                LED_Data <<= 1;
            else
                LED_Data >>= 1;
            timer2Cnt = 0;
        }
        PORTC = LED_Data;
    }
}
ISR(TIMER2_OVF_vect)
{
    cli();
    TCNT2 = 112; // 113, 114, ... , 255 (144 > 0.0025 초)
    timer2Cnt++;
    sei();
}