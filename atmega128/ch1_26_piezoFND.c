#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

uint16_t doReMi[4] = {523, 587, 659}; //{523, 587, 659, 698, 783, 880, 987, 1046};
uint8_t piano = 0;
volatile uint8_t switch_flag = 0;
uint8_t numbers[4] = {0x3F, 0x06, 0x5B, 0x4F}; // 123456789
volatile uint8_t timeS = 0x01;
volatile uint8_t fndFlag = 0, edgeFlag = 0;

int main()
{
    // PB7 핀 피에조 -> OCR1C
    DDRB = _BV(PB7); // 7번 출력 설정
    DDRA = 0xFF;
    DDRE = 0x00;

    TCCR3A = 0x00;
    TCCR3B = 0x45; // 분주비 1024 16Mhz 160000000/256 = 62500
    ETIMSK = _BV(TICIE3);
    ETIFR |= _BV(ICF3);

    TCCR1A = _BV(COM1C1) | _BV(WGM11);            // com 10 -> clear on compare
    TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS00); // 분주비 1, fast PWM
    EIMSK = 0xF0;                                 // 0b10100000 INT5, INT7
    EICRB = 0xFF;                                 //_BV(ISC71) | _BV(ISC70) | _BV(ISC51);
    EIFR = 0xF0;                                  // 플래그 클리어

    sei(); // 전역 인터럽트 허용

    while (1)
    {
        PORTA = numbers[switch_flag];
        if (fndFlag)
        {
            if (timeS > 10)
            {
                timeS = 10;
                ICR1 = 14745600 / doReMi[switch_flag]; // 주파수 만큼 duty cycle을 설정 하겠다.
                OCR1C = ICR1 / 2;                      // 절반을 on 시키겠다.
                fndFlag = 0;
            }
        }          // numbers[switch_flag];
    }
    return 0;
}
ISR(INT4_vect)
{
    cli();
    switch_flag = 0;
    ICR1 = 14745600 / doReMi[switch_flag]; // 주파수 만큼 duty cycle을 설정 하겠다.
    OCR1C = ICR1 / 2;
    sei();
}

ISR(INT5_vect)
{
    cli();
    switch_flag = 1;
    ICR1 = 14745600 / doReMi[switch_flag]; // 주파수 만큼 duty cycle을 설정 하겠다.
    OCR1C = ICR1 / 2;
    sei();
}

ISR(INT6_vect)
{
    cli();
    switch_flag = 2;
    ICR1 = 14745600 / doReMi[switch_flag]; // 주파수 만큼 duty cycle을 설정 하겠다.
    OCR1C = ICR1 / 2;
    sei();
}

ISR(INT7_vect)
{
    cli();
    switch_flag = 3;
    ICR1 = 14745600 / doReMi[switch_flag]; // 주파수 만큼 duty cycle을 설정 하겠다.
    OCR1C = ICR1 / 2;
    sei();
}

ISR(TIMER3_CAPT_vect)
{
    cli();
    uint16_t count_check;
    if (edgeFlag == 0)
    {
        TCCR3B = 0x05;
        TCNT3 = 0;
        ICR3 = 0; // 캡처 카운트
        edgeFlag = 1;
    }
    else
    {
        TCCR3B = 0x45; // 분주비 1024 상승엣지 트리거
        count_check = ICR3;
        timeS = count_check / 1440; // 0.1초 단위
        fndFlag = 1;
        edgeFlag = 0;
    }
    sei();
}