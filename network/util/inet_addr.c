#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

void print_addr(unsigned long conv_addr);

int main()
{
    char *addr1 = "127.212.124.78";  // 0x4e7cd47f ==
    char *addr2 = "127.212.124.256"; // 256 Error
    struct sockaddr_in addr_inet;
    struct sockaddr_in addr_inet2;

    unsigned long conv_addr = inet_addr(addr1);
    print_addr(conv_addr);

    conv_addr = inet_addr(addr2);
    print_addr(conv_addr);

    int ret = inet_pton(AF_INET, addr1, &addr_inet.sin_addr);
    if (ret)
    {
        printf("Network int addr : %#x\n", addr_inet.sin_addr.s_addr);
        printf("socket_addr s_data : %#x\n", ((struct sockaddr *)&addr_inet)->sa_data);
    }
    char buffer[20];
    char *buffer_ptr;

    buffer_ptr = inet_ntoa(addr_inet.sin_addr);
    strcpy(buffer, buffer_ptr);
    printf("Network type(111.111.111.111) string : %s \n", buffer);

    addr_inet2.sin_addr.s_addr = htonl(0x10203040);

    // buffer_ptr = inet_ntoa(addr_inet2.sin_addr);
    // strcpy(buffer, buffer_ptr);
    printf("Network type(111.111.111.111) string : %s \n", inet_ntoa(addr_inet2.sin_addr));

    return 0;
}

void print_addr(unsigned long conv_addr)
{
    if (conv_addr == INADDR_NONE)
    {
        printf("Error occured \n");
    }
    else
    {
        printf("Network's int addr : %#lx \n", conv_addr);
    }
}