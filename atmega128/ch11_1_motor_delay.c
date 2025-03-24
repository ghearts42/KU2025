#include <util/delay.h>
#include <avr/io.h>

int main(void)
{

    DDRD = _BV(PD4) | _BV(PD5); // 7번 출력 설정
    DDRB = _BV(PB5);

    while (1)
    {
        PORTD |= _BV(PD4); // M1 정회전
        PORTB |= _BV(PB5); // M1 회전
        _delay_ms(500);
        PORTD &= ~_BV(PD4);
        PORTD |= _BV(PD5);
        PORTB |= _BV(PB5); // M1 회전
        _delay_ms(500);
    }

    return 0;
}