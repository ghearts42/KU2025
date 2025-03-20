// UART를 이용하여 시리얼 통신으로 센서값이 0.1초 간격으로 표시되도록 작성하기
// ex) CDS ADC_data : xxx

#include "lcd.h"
#include "uart0.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>

volatile uint16_t adcResult = 0;

int main()
{
    lcdInit();
    uart0Init();

    stdin = &INPUT;
    stdout = &OUTPUT; // 위 4줄로 printf, scanf 사용 가능

    ADMUX = 0x40;   // ADC0 single mode, 0번 채널, 3.3v 외부 기준 전압(AREF)
    ADCSRA = 0xAF;  // 10101111 ADC 허가, free running mode, Interrupt en, 128분주비
    DDRE = 0x02;    // Rx(입력) Tx(출력) = 1, SW0~3 입력
    ADCSRA |= 0x40; // ADC 개시

    sei();

    printf("Hi, I'm ATmega128.");

    lcdGotoXY(0, 0);
    lcdPrintData("Light Sensor", 12);
    char buf[16];

    while (1)
    {
        lcdGotoXY(0, 1);
        sprintf(buf, "L: %u", adcResult);
        lcdPrintData(buf, strlen(buf));
        _delay_ms(1000);
        if (adcResult != '0')
        {
            printf("\n\r CDS ADC_data : %d", adcResult);
        }
    }
    return 0;
}

ISR(ADC_vect)
{
    cli();
    adcResult = ADC; // 2^16 = 0 ~ 1023
    sei();
}