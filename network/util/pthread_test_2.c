#include <pthread.h> // pthread_create, pthread_join 등 스레드 관련 함수
#include <stdio.h>   // printf, puts 등 표준 입출력 함수
#include <stdlib.h>  // malloc, free, exit 등 메모리/종료 함수
#include <string.h>  // strcpy 등 문자열 함수
#include <unistd.h>  // sleep 함수

char *thread_main(void *arg);

int main()
{
    pthread_t t_id;       // 새로 생성할 스레드의 ID를 저장할 변수입니다.
    int thread_param = 5; // 스레드에 넘길 파라미터. 여기서는 반복 횟수로 사용됩
    char *thr_ret;        // 스레드가 반환하는 값을 저장할 포인터

    pthread_create(&t_id, NULL, (void *)thread_main, (void *)&thread_param);
    // 스레드 동작 생성 (생성 스레드 ID 저장, 스레드 속성, 실행할 함수, 함수에 전달할 인자)
    pthread_join(t_id, &thr_ret); // 쓰레드가 리턴 될때까지 대기!!
    for (int i = 0; i < 10; i++)
    {
        sleep(1);
        puts("running main()");
    }
    printf("쓰레드에서 받아온 메세지: %s \n", (char *)thr_ret);
    free(thr_ret);
    return 0;
}

char *thread_main(void *arg)
{
    int cnt = *((int *)arg);
    char *msg = (char *)malloc(sizeof(char) * 50);
    strcpy(msg, "Hello, I'am from thread--- \n");
    for (int i = 0; i < cnt; i++)
    {
        sleep(1);
        puts("running thread_main()");
    }
    return msg;
}