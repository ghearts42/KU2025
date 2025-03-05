// 볼드, 이탤릭, 쉐도우, 언더라인을 표현하는 변수를 만들어라이라이라이라이차차차
// 비트 연산
#include <stdio.h>
// 볼드 1 자리 비트 : 0b00000001
// 이탤릭 2 자리 비트   : 0b00000010
// 쉐도우 3 자리 비트   : 0b00000100
// 언더라인 4 자리 비트 : 0b00001000

//define
#define BOLD 0x01
#define ITALIC (0x01 << 1)      //0x02
#define SHADOW (0x01 << 2)      //0x04
#define UNDERLINE (0x01 << 3)   //0x08

void printAttrib(unsigned char attr);

int main(void){
    unsigned char attr; // 8bit 8개 속성
    attr = attr ^ attr; // 모두 0
    attr = attr | BOLD; //atrr를 볼드로 설정
    printAttrib(attr);
    attr = attr | (ITALIC | SHADOW); //atrr 이탤릭 쉐도우 추가
    printAttrib(attr);
    attr = attr & (~BOLD);
    printAttrib(attr);
    
    return 0;
}

void printAttrib(unsigned char attr){
    printf("attr %d\n", attr);
    printf("BOLD : %d\n", (attr & BOLD));
    printf("ITALIC : %d\n", ((attr & ITALIC)>>1));
    printf("SHADOW : %d\n", ((attr & SHADOW)>>2));
    printf("UNDERLINE : %d\n", ((attr & UNDERLINE)>>3));
    printf("------------------------------------\n");

}