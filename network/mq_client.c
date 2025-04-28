#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUEUE_NAME "/myqueue"
#define MAX_MSG_SIZE 128

int main()
{
    mqd_t mq = mq_open(QUEUE_NAME, O_WRONLY);
    char buffer[] = "Hello from Client";

    mq_send(mq, buffer, strlen(buffer) + 1, 0);
    printf("Sent message : %s\n", buffer);

    mq_close(mq);

    return 0;
}