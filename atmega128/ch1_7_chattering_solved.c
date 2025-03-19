#include <avr/io.h>
#include <avr/delay.h>

int main()
{
    DDRC = 0x01;  // port 0번 비트 출력
    PORTE = 0xFF; // 풀업 설정
    PORTC = 0x00;
    while (1)
    {
        _delay_ms(20);
        if (!(PINE >> 2 & _BV(PC0)))
        {
            PORTC ^= 0x01; // 버튼 반전
            // 버튼이 눌릴 때 까지 대기
            while (!(PINE >> 2) & _BV(PC0))
            {
                _delay_ms(10);
            }
        }
    }

    return 0;
}