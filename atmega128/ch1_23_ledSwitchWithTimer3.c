
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t LED_Data = 0x01;
volatile uint8_t direction = 0;

int main(void)
{
    DDRC = 0x0f; // 1111 | 0123 출력 포트로 설정

    TCCR3A = 0x00;
    TCCR3B = _BV(CS32); // 분주비 1024 16Mhz 160000000/256 = 62500
    // TCCR1B = _BV(CS10); // 분주비 1
    ETIMSK = _BV(TOIE3);
    TCNT3 = 46766;
    // TCCR1B = 0x01; // 분주비 1

    sei(); // 전역 인터럽트 허용

    while (1)
    {
        PORTC = LED_Data;
    }
}

ISR(TIMER3_OVF_vect)
{
    cli();
    TCNT3 = 46766;
    if (LED_Data > 0x04)
    {
        direction = 0;
    }
    if (LED_Data == 1)
    {
        direction = 1;
    }
    if (direction)
    {
        LED_Data <<= 1;
    }
    else
    {
        LED_Data >>= 1;
    }
    PORTC = LED_Data;
    sei();
}