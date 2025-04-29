// ./hello_server
// ./hello_client 127.0.0.1 8888

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int serv_sock;
    int clnt_sock;

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;

    // 포트 번호 미입력시 에러처리 후 종료
    if (argc != 2)
    {
        printf("사용법: %s <port>\n", argv[0]);
        exit(1);
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, 0); // TCP 설정
    // socket(IPv4 프로토콜, TCP, 0(기본 프로토콜))

    memset(&serv_addr, 0, sizeof(serv_addr)); // 구조체 초기화
    serv_addr.sin_family = AF_INET;           // IPv4 사용
    // serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY > 어떤 IP 주소든 받아옴
    serv_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    serv_addr.sin_port = htons(atoi(argv[1]));

    int option = 1;
    setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

    bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    // 서버 소켓을 serv_addr에 바인드

    while (1)
    {
        listen(serv_sock, 5); // 클라이언트 연결 대기 -> 5개까지 동시 대기 가능
        clnt_addr_size = sizeof(clnt_addr);
        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
        // 연결된 상태의 코드....
        // char message[] = "Hello, TCP IP!!";
        // write(clnt_sock, message, sizeof(message)); //서버 -> 클라이언트로 보내게 되어있는 메시지 코드
        char message[30];
        read(clnt_sock, message, sizeof(message) - 1);
        message[29] = '\0';
        printf("서버 받은 메세지: %s \n", message);
        close(clnt_sock);
    }

    close(serv_sock);

    return 0;
}