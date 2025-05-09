#include <avr/io.h>

void uart1Init(void)
{
    UCSR0A |= _BV(U2X1); // 2배속 모드
    UCSR0B = 0x18;       // 0b00011000 Rx, Tx enable
    UCSR0C |= 0x16;      // 0b00010110 비동기 no Parity, 1 stop bit

    UBRR0H = 0x00;
    UBRR0L = 0x07; // 115200 BPS > 9600 bsp
}

void iart1Transmit(char data);

unsigned char uart1Receive(void)
{
    while ((UCSR0A & 0x80) == 0)
    {
        ;
    }
    return UDR0;
}
void uart1PrintString(char *str);
void uart1Print1ByteNumber(unsigned char n);