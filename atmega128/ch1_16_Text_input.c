#include "lcd.h"
#include "uart0.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

volatile uint8_t intData;
uint8_t cursor = 0;

int main()
{
    uart0Init();
    lcdInit();
    stdin = &INPUT;
    stdout = &OUTPUT; // 위 4줄로 printf, scanf 사용 가능

    DDRE = 0x02; // Rx(입력) Tx(출력) = 1, SW0~3 입력

    EICRB = 0xFF; // 4567 상승엣지 적용 0b11111111
    EIMSK = 0xF0;
    EIFR = 0xF0;

    sei();
    char cData;
    // char buffer[30];
    printf("Hi, I'm ATmega128.");
    lcdGotoXY(0, 0);

    while (1)
    {
        if (intData != '0')
        {
            printf("\n\r Input Switch : %c", intData);
            intData = '0';
        }
        while (UCSR0A & (1 << RXC0))
        {
            cData = fgetc(stdin);
            lcdDataWrite(cData);
            // scanf("%s", buffer);
            // lcdPrint(buffer);
            cursor++;
            if (cursor == 16)
            {
                lcdGotoXY(0, 1);
            }
            else if (cursor >= 32)
            {
                cursor = 0;
                lcdGotoXY(0, 0);
            }
        }
    }
    return 0;
}

ISR(INT4_vect)
{
    cli();
    intData = '1';
    sei();
}

ISR(INT5_vect)
{
    cli();
    intData = '2';
    sei();
}

ISR(INT6_vect)
{
    cli();
    intData = '3';
    sei();
}

ISR(INT7_vect)
{
    cli();
    intData = '4';
    sei();
}