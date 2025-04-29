#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

#define BUFFER_SIZE 256

int main()
{
    int pipe1_fd[2]; // 부모 -> 자식
    int pipe2_fd[2]; // 자식 -> 부모 각각의 fd[0]은 읽기, fd[1]은 쓰기
    pid_t pid;       // fork 후에 부모/자식의 구분에 사용
    char buffer[BUFFER_SIZE];

    pipe(pipe1_fd);
    pipe(pipe2_fd); // 파이프 생성, 실제 개발시에 예외 처리 필요

    pid = fork(); // 0이면 자식, 0 < pid 면 부모 프로세스
    if (pid == 0)
    {
        // 자식
        close(pipe1_fd[1]); // 부모->자식 파이프의 쓰기 끝 닫기
        close(pipe2_fd[0]); // 자식->부모 파이프의 읽기 끝 닫기
        // 쓰지 않는 파이프를 닫음
        read(pipe1_fd[0], buffer, BUFFER_SIZE); // 대기.
        printf("Child received: %s\n", buffer);

        char *response = "Hello from Child!";
        write(pipe2_fd[1], response, strlen(response) + 1);

        close(pipe1_fd[0]); // 부모->자식 파이프의 읽기 끝 닫기
        close(pipe2_fd[1]); // 자식->부모 파이프의 쓰기 끝 닫기
        // 끝난 프로세스의 파이프는 닫아주어야 함.
        exit(EXIT_SUCCESS);
    }
    else
    {
        // 부모 프로세스
        close(pipe1_fd[0]); // 부모->자식 파이프의 읽기 끝 닫기
        close(pipe2_fd[1]); // 자식->부모 파이프의 쓰기 끝 닫기
        char *message = "Hello from Parent!";
        write(pipe1_fd[1], message, strlen(message) + 1);
        getchar();
        read(pipe2_fd[0], buffer, BUFFER_SIZE); // 대기
        printf("Parent received: %s\n", buffer);

        close(pipe1_fd[1]); // 부모->자식 파이프의 쓰기 끝 닫기
        close(pipe2_fd[0]); // 자식->부모 파이프의 읽기 끝 닫기
        wait(NULL);
        printf("자식 프로세스 종료.\n");
    }

    return 0;
}

// 파이프는 단방향이므로 파이프 2개를 생성 (부모->자식, 자식->부모)
// 포크 후에 정리하지 않으면 데드락 발생 가능성 있음
// RD/WR는 블로킹 함수(A 함수가 B 함수를 호출하면, 제어권을 A가 호출한 B 함수에 넘기는 형식의 함수)이므로 상대방의 동작을 기다림
// 문자열 전송시에는 NULL 까지 전송하므로 strlen + 1