#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

uint16_t CDE[4] = {523, 587, 659, 698}; //{523, 587, 659, 698, 783, 880, 987, 1046};
volatile uint8_t playBuzzer = 0;
volatile uint8_t piano = 0;
volatile uint8_t switch_flag = 0;
uint8_t numbers[4] = {0x3F, 0x06, 0x5B, 0x4F}; // 123456789
#define PWM_SETUP _BV(COM3A1) | _BV(WGM31)

// volatile uint8_t timeS = 0x01;
// volatile uint8_t fndFlag = 0, edgeFlag = 0;

int main()
{
    // PB7 핀 피에조 -> OCR1C
    DDRE = 0x08;
    DDRA = 0xFF;

    // DDRB = _BV(PB7); // 7번 출력 설정

    TCCR3A = PWM_SETUP;
    TCCR3B = _BV(WGM33) | _BV(WGM32) | _BV(CS00); // 분주비 1024 16Mhz 160000000/256 = 62500

    TCCR3C = 0x00;

    EIMSK = (1 << INT4)|(1 << INT5)|(1 << INT6)|(1 << INT7);//0xF0; // 0b10100000 INT5, INT7
    EICRB = 0xFF; //_BV(ISC71) | _BV(ISC70) | _BV(ISC51);
    // EIFR = 0xF0;                                  // 플래그 클리어

    sei(); // 전역 인터럽트 허용

    while (1)
    {
        if (playBuzzer)
        {
            // 스위치에 맞는 소리내기
            ICR3 = 14745600 / CDE[piano];
            OCR3A = ICR3 / 2;
            TCCR3A = PWM_SETUP;
            TCCR3B = _BV(WGM33) | _BV(WGM32) | _BV(CS00); // 분주비 1, fast PWM
            PORTA = numbers[piano];

            _delay_ms(2000);
            TCCR3A = 0x00; // 버저 끄기
            PORTA = 0x00;  // FND 끄기
            playBuzzer = 0;
        } // numbers[switch_flag];
    }
    return 0;
}
ISR(INT4_vect)
{
    cli(); // sei() 반대 설정 SREG -> I unset -> 0
    playBuzzer = 1;
    piano = 0;
    sei();
}

ISR(INT5_vect)
{
    cli();
    playBuzzer = 1;
    piano = 1;
    sei();
}
ISR(INT6_vect)
{
    cli();
    playBuzzer = 1;
    piano = 2;
    sei();
}

ISR(INT7_vect)
{
    cli();
    playBuzzer = 1;
    piano = 3;
    sei();
}