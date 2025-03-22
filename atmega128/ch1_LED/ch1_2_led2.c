#include <avr/io.h>
// AVR 입출력에 대한 헤더 파일
#include <util/delay.h> // delay 함수사용을 위한 헤더파일

int main(void)
{
    while (1)
    {
        // *(volatile uint8_t *)(0x14) = 0x03;
        DDRC = 0x03; // 0011 0,1을 출력 포트로 설정
        // PORTC |= (1 << PC0) | (1 << PC1) |(1 << PC2) | (1 << PC3);
        // PORTC |= _BV(PC0) | _BV(PC1) | _BV(PC2) | _BV(PC3);
        PORTC = 0x0F; // 1111 0,1,2,3을 1(ON) > 5V 출력
        _delay_ms(500);  // ms 단위의 딜레이 함수

        PORTC = 0x00;   //0000 0,1,2,3을 0(OFF) > 0V로 출력
        _delay_ms(500);  // ms 단위의 딜레이 함수
    }
}
