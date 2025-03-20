#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t ledData = 0x00;
uint8_t timer0Cnt = 0;
ISR(TIMER0_OVF_vect);

int main(void)
{
    DDRC = 0x0F;
    TCCR0 = _BV(CS02) | _BV(CS01) | _BV(CS00);
    TCNT0 = _BV(CS02) | _BV(CS01) | _BV(CS00);
    // TCNT0 = 112;

    TIMSK |= _BV(TOIE0);
    TIFR |= _BV(TOV0);

    sei();

    while (1)
    {

        if (timer0Cnt == 100)
        {
            ledData++;
            if(ledData > 0x0F)
            {
                ledData = 0;
            }
            timer0Cnt = 0;
        }
    
        PORTC = ledData;
    }
}
ISR(TIMER0_OVF_vect)
{
    cli();
    TCNT0 = 112; // 113, 114, ... , 255 (144 > 0.0025 초)
    timer0Cnt++;
    sei();
}