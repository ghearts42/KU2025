#include <stdio.h>      // 표준 입출력 함수 (printf, perror 등)
#include <stdlib.h>     // exit(), atoi() 등
#include <string.h>     // memset(), strlen() 등
#include <unistd.h>     // POSIX API: read(), write(), close()
#include <arpa/inet.h>  // 주소 변환 함수: htons(), inet_addr() 등
#include <sys/socket.h> // 소켓 함수: socket(), bind(), listen(), accept() 등

void error_handling(char *message); // 에러 처리 함수의 선언

int main(int argc, char *argv[]) // argc는 인자 개수, argv는 인자 배열 ex) ./server 8080 실행 시, argv[1] = "8080"
{
    int serv_sock;
    int clnt_sock; // 서버 및 클라이언트 소켓 준비

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr; // 서버와 클라이언트의 주소 정보를 담을 구조체

    socklen_t clnt_addr_size; // accept() 함수에서 클라이언트 주소 크기를 넘기기 위한 변수

    char message[] = "hello,world"; // 클라이언트에 보낼 문자열

    if (argc != 2)
    {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    } // 명령줄 인자로 포트 번호가 제공되지 않았을 경우 사용법을 출력하고 종료

    serv_sock = socket(PF_INET, SOCK_STREAM, 0); // 소켓 생성

    if (serv_sock == -1)
    {
        error_handling("socket()) error");
    } // 소켓 생성 오류 시의 예외처리

    memset(&serv_addr, 0, sizeof(serv_addr));      // 안전한 사용을 위한 구조체 초기화
    serv_addr.sin_family = AF_INET;                // 주소 체계 IPv4
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // 모든 IP에서의 접속 허용, Host to Network Long 네트워크 바이트 순서로 변환
    serv_addr.sin_port = htons(atoi(argv[1]));     // 포트 번호 숫자로 변경 후 Host to Network Short 네트워크 바이트 순서로 변환

    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        error_handling("bind() error");
    } // 서버 소켓을 지정한 IP/포트에 bind, 실패 시 예외 처리

    if (listen(serv_sock, 5) == -1)
    {
        error_handling("listen() error");
    } // 서버 소켓 수신 대기 상태로 전환, 예외처리

    clnt_addr_size = sizeof(clnt_addr); //

    clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size); // 클라이언트 IP/포트 정보를 저장하고 클라이언트 연결 수락
    if (clnt_sock == -1)
    {
        error_handling("accept() error");
    } // 예외 처리

    write(clnt_sock, message, sizeof(message)); // 데이터 전송
    close(clnt_sock);
    close(serv_sock); // 소켓 폐쇄
    return 0;
}

void error_handling(char *message) // 오류 메시지 출력하는 함수
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}