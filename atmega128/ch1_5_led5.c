#include <avr/io.h>
#include <util/delay.h>

int main()
{
    while (1)
    {
        unsigned char switch_flag = 0;
        DDRE = 0x00; //8개의 핀을 모두 인풋
        PORTE = 0x00; //출력 - 풀업을 설정.
        DDRC = 0x0f; //아웃풋
        //PINE
        while (1)
        {
            if (PINE >> 4) //PIN E
            {
                switch_flag = PINE >> 4; // 0b1000 0b0100
                PORTC = switch_flag;
            }

        }
        
    }
    return 0;
}