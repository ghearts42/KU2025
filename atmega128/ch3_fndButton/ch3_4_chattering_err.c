#include <avr/io.h> // AVR 입출력에 대한 헤더 파일

int main(void)
{
    unsigned char switchFlag = 0;
    DDRC = 0x0F;  // LED 출력설정
    PORTE = 0x01; // 풀 업 설 정

    while (1)
    {
        if (PINE & _BV(PE0))
        {
            switchFlag = PINE;
        }
        if (!(switchFlag & _BV(PE0)))
        {
            PORTC ^= 0x01; // 1번 비트 반전 XOR 연산
        }
        // PORTC ^= 0x01; // 1번 비트 반전 XOR 연산 00,11 > 0 01,10 > 1
    }

    return 0;
}
// 채터링 문제가 일어나 버튼 반전이 제대로 이루어지지 않을 수 있음