#define F_CPU 160000000L // 내부 변수
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

volatile unsigned long milliseconds = 0;

ISR(TIMER0_OVF_vect)
{
    ++milliseconds;
}

// timer0활성화
void timer0_init(void)
{
    TCCR0 = _BV(CS02) | _BV(CS01) | _BV(CS00);
    // TCNT0 = 6;
    TIMSK |= _BV(TOIE0);
    sei();
}

int main()
{
    timer0_init();
    uint8_t numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67}; // 123456789

    int count = 0;
    DDRA = 0xFF;

    while (1)
    {
        if (milliseconds >= 4)
        {
            milliseconds = 0;
            count = (count + 1) % 10;
            PORTA = numbers[count];
        }
    }

    return 0;
}