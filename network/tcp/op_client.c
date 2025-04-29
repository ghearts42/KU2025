#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 1024
void error_handling(char *message); // 에러 처리 함수

int main(int argc, char *argv[])
{
    int sock;

    struct sockaddr_in serv_addr; // 클라이언트 소켓 및 주소 정보 구조체 선언

    if (argc != 3)
    {
        printf("사용법: %s <IP> <port>\n", argv[0]);
        exit(1);
    } // 인자로 서버 IP 및 포트 번호를 받아야 함

    sock = socket(PF_INET, SOCK_STREAM, 0); // TCP 설정
    if (sock == -1)
    {
        error_handling("socker() 열기 실패!!");
    } // TCP 소켓 생성

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]); // localhost 는 입력 받을 수 없는 코드
    serv_addr.sin_port = htons(atoi(argv[2]));
    // 구조체 초기화, 문자열 IP 주소를 4byte 숫자로, 포트 번호를 네트워크 바이트 순서로 변환

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        error_handling("connet() 연결 실패!!!"); // listen 상태의 서버에 접속
    }
    else
    {
        puts("Connected............");
    }
    char message[BUF_SIZE]; // 서버에 전송할 메시지를 담는 배열
    int str_len, recv_len, recv_cnt;
    int result, opnd_cnt, i;

    fputs("피 연산자 객수를 넣으세요!: ", stdout);
    scanf("%d", &opnd_cnt);
    message[0] = (char)opnd_cnt; // 첫 번째 바이트에 피연산자 개수 저장

    for (i = 0; i < opnd_cnt; ++i)
    {
        printf(" %d 번째 피 연산자 를 넣으세요!: ", i + 1);
        scanf("%d", (int *)&message[i * 4 + 1]);
    }
    fgetc(stdin); // 버퍼에 남은것 버리기
    fputs("연산자를 넣으세요! :", stdout);
    scanf("%c", &message[opnd_cnt * 4 + 1]);
    fputs("메세지는 !!: ", stdout);
    fputc(message[0], stdout);
    fputc(message[1], stdout);
    fputc(message[2], stdout);
    fputc(message[3], stdout);
    fputc(message[4], stdout);
    fputc(message[5], stdout);
    fputc(message[6], stdout);
    fputc(message[7], stdout);
    fputc(message[8], stdout);
    fputc(message[9], stdout);
    fputs("메세지는 !!: ", stdout);

    write(sock, message, opnd_cnt * 4 + 2); // 피연산자와 그 갯수와 연산자 전송

    read(sock, &result, 4);

    printf("연산의 결과는: %d \n", result);
    close(sock);

    return 0;
}
void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}