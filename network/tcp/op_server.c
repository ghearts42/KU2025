// ./hello_server
// ./hello_client 127.0.0.1 8888

// Header
#include <arpa/inet.h>  // IP 주소 변환 등 네트워크 관련
#include <stdio.h>      // 입출력 (printf, fprintf 등)
#include <stdlib.h>     // exit, atoi, malloc 등
#include <string.h>     // memset 등 문자열 처리
#include <sys/socket.h> // 소켓 관련 함수
#include <unistd.h>     // close, read, write

// Used Function
void error_handling(char *message);
int calculate(int opnum, int opnds[], char op);

// Used Macro
#define BUF_SIZE 1024 // 수신 데이터에 대한 최대 크기 지정

// Main fuction
int main(int argc, char *argv[])
{

    int serv_sock; // 서버 소켓(네트워크 상에서 사용 가능한 소프트웨어 장치)
    int clnt_sock; // 클라이언트 소켓
    int str_len;   //

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr; // 서버와 클라이언트 주소 정보에 대한 구조체
    socklen_t clnt_addr_size;

    if (argc != 2)
    {
        printf("사용법: %s <port>\n", argv[0]);
        exit(1);
    } // 실행 시에 포트 번호를 인자로 받기 위한 코드

    serv_sock = socket(PF_INET, SOCK_STREAM, 0); // TCP 설정
    if (serv_sock == -1)
    {
        error_handling("socker() 만들기 실패");
    } // TCP용 소켓 (PF_INET: IPv4, SOCK_STREAM: TCP) 생성 및 오류 처리

    memset(&serv_addr, 0, sizeof(serv_addr));      // 서버 주소 정보 구조체를 초기화함
    serv_addr.sin_family = AF_INET;                // IPv4 로 설정
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // 모든 IP의 접속을 승인함
    serv_addr.sin_port = htons(atoi(argv[1]));     // 포트를 네트워크 바이트 순서로 변환함.
    // 서버 주소 정보 설정

    int option = 1;
    setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
    // 서버 재시작 시 포트 재사용 허용

    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        error_handling("Bind Error");
    } // bind: 소켓에 IP주소와 포트를 연결

    if (listen(serv_sock, 5) == -1)
    {
        error_handling("Listen Error"); //
    } // listen: 클라이언트 연결을 기다리는 상태로 만듦 (대기열: 5)

    int opnd_cnt = 0;
    int recv_len = 0, recv_cnt;
    char opinfo[BUF_SIZE];
    int result;

    for (int i = 0; i < 20; ++i)
    {
        clnt_addr_size = sizeof(clnt_addr);
        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
        // 클라이언트가 연결 요청하면 수락
        if (clnt_sock == -1)
        {
            error_handling("accept() 에러!!");
        }
        else
        {
            printf("Conneted client %d : %s \n", i + 1, inet_ntoa(clnt_addr.sin_addr)); // inet_ntoa()로 클라이언트 IP 주소 출력
        }

        read(clnt_sock, &opnd_cnt, 1);
        printf("피연산자 갯수%d\n", opnd_cnt);
        // 먼저 피연산자 개수(1바이트)를 읽음
        recv_len = 0;
        while ((opnd_cnt * 4 + 1) > recv_len) // 피연산자 개수 * 4 + 1 만큼 수신
        {
            recv_cnt = read(clnt_sock, &opinfo[recv_len], BUF_SIZE - 1);
            recv_len += recv_cnt;
        }
        printf("recv_len : %d", recv_len);
        printf("연산자 : %c", opinfo[recv_len - 1]);
        result = calculate(opnd_cnt, (int *)opinfo, opinfo[recv_len - 1]);
        // 피연산자 배열 + 마지막에 연산자(recv_len - 1)
        write(clnt_sock, (char *)&result, sizeof(result));
        close(clnt_sock); // 계산 결과 전송 후 소켓 닫기
    }

    close(serv_sock);

    return 0;
}

// 에러 처리하는 함수
void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

// 입력한 연산자에 따른 기능 수행
int calculate(int opnum, int opnds[], char op)
{
    int result = opnds[0], i;
    switch (op)
    {
    case '+':
        for (i = 1; i < opnum; ++i)
            result += opnds[i];
        break;
    case '*':
        for (i = 1; i < opnum; ++i)
            result *= opnds[i];
        break;
    case '-':
        for (i = 1; i < opnum; ++i)
            result -= opnds[i];
        break;
    default:
        result = 0;
    }

    return result;
}