#include <util/delay.h>
#include <avr/io.h>
#include <avr/delay.h>

int main()
{
    DDRC = 0x01;  // PORTC의 0번 비트 출력모드
    PORTE = 0xFF; // 풀업 설정

    while (1)
    {
        _delay_ms(20);
        if (!(PINE & _BV(PC0)))
        {
            PORTC ^= _BV(PC0); // 버튼 반전
            // 버튼이 눌릴 때 까지 대기
            while (!(PINE)&_BV(PC0))
            {
                _delay_ms(10);
            }
        }
    }

    return 0;
}