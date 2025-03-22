// 인터럽트로 FND를 점멸
// INT5 P1 > 2, P2 > 1
//  1페 FND가 빠르게 상승하는 코드 100ms
//  2페 FND가 멈춤

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t switch_flag = 0;

int main()
{
    DDRA = 0xFF;
    DDRE = 0x00;

    uint8_t numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67}; // 123456789
    int count = 0;

    EIMSK = 0xA0; // 0b10100000 INT5, INT7
    EICRB = 0xC8; // 0b11001000 인터럽트 5는 하강, 7는 상승
    // EICRB = _BV(ISC71) | _BV(ISC70) | _BV(ISC51);
    EIFR = 0xA0; // 플래그 클리어
    sei();

    while (1)
    {
        PORTA = numbers[count];
        if (switch_flag != 2)
        {
            count = (count + 1) % 10;
        }
        else
        {
            count = count;
        }
        _delay_ms(200);
    }
    return 0;
}
ISR(INT5_vect)
{
    cli();
    switch_flag = 0;
    sei();
}

ISR(INT7_vect)
{
    cli();
    switch_flag = 2;
    sei();
}