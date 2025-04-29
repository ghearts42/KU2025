#include <stdio.h>
#include <arpa/inet.h>

int main()
{
    unsigned short host_port = 0x1234;
    unsigned short net_port;
    unsigned long host_addr = 0x12345678;
    unsigned long net_addr;

    net_port = htons(host_port);
    net_addr = htonl(host_addr);

    printf("호스트 포트 = %#x \n", host_port);
    printf("네트워크 포트 = %#x \n", net_port);
    printf("호스트 주소 = %#lx \n", host_addr);
    printf("네트워크 주소 = %#lx \n", net_addr);

    return 0;
}

// 호스트 포트 = 0x1234
// 네트워크 포트 = 0x3412
// 호스트 주소 = 0x12345678
// 네트워크 주소 = 0x78563412
// 네트워크와 호스트의 엔디안이 다르다