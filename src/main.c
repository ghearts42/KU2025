
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

uint8_t numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67}; // 123456789
volatile uint8_t timeS = 0x01;

int main(void)
{
    DDRA = 0xff; // 1111 | 0123 출력 포트로 설정
    DDRE = 0x00;
    
    TCCR1A = 0x00;
    TCCR1B = 0x05; // 분주비 1024 16Mhz 160000000/256 = 62500
    // TCCR1B = _BV(CS10); // 분주비 1

    OCR1A = 14400;
    OCR1B = 28800;

    TIMSK = _BV(OCIE1A) | _BV(OCIE1B) | _BV(TOIE1);//0x10; //
    // ETIFR |= _BV(ICF3);
    sei(); // 전역 인터럽트 허용

    PORTA = numbers[0];

    while (1)
    {
        PORTA = numbers[timeS];
        if(timeS > 9)
            timeS = 0;
    }
}

ISR(TIMER1_COMPA_vect)
{
    cli();
    // OCR1A += 14400;
    timeS++;
    sei();
}

ISR(TIMER1_COMPB_vect)
{
    cli();
    // OCR1A += 14400;
    timeS--;
    sei();
}

ISR(TIMER1_OVF_vect)
{
    cli();
    // OCR1A += 14400;
    timeS++;
    sei();
}