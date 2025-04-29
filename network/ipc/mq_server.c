#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUEUE_NAME "/myqueue"
#define MAX_MSG_SIZE 128
#define QUEUE_PERMS 0666

int main()
{
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10; // 저장 가능한 큐 버퍼 개수
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;

    mqd_t mq = mq_open(QUEUE_NAME, O_CREAT | O_RDONLY, QUEUE_PERMS, &attr);

    char buffer[MAX_MSG_SIZE + 1];
    ssize_t bytes_read;

    bytes_read = mq_receive(mq, buffer, MAX_MSG_SIZE + 1, NULL);
    buffer[bytes_read] = '\0';
    printf("Recieved message : %s\n", buffer);

    mq_close(mq);
    mq_unlink(QUEUE_NAME);

    return 0;
}