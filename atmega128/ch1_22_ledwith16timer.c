
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t LED_Data = 0x01;

ISR(TIMER2_OVF_vect);

int main(void)
{
    DDRC = 0x0f; // 1111 | 0123 출력 포트로 설정

    TCCR1A = 0x00;
    TCCR1B = _BV(CS10) | _BV(CS12); // 분주비 1024 16Mhz 160000000/1024 = 15625
    // TCCR1B = _BV(CS10); // 분주비 1
    TIMSK = _BV(TOIE1);
    TCNT1 = 49910;
    // TCCR1B = 0x01; // 분주비 1
    TIMSK = 0x04;

    sei(); // 전역 인터럽트 허용

    while (1)
    {
        _delay_ms(100);
    }
    return 0;
}

ISR(TIMER1_OVF_vect)
{
    cli();
    TCNT1 = 49910;
    PORTC = LED_Data;
    LED_Data++;
    if (LED_Data > 0x0F)
    {
        LED_Data = 0;
    }
}