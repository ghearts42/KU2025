#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void timeoutCallback(int sig);
void keycontrolCallback(int sig);

int main()
{
    signal(SIGALRM, timeoutCallback);
    signal(SIGINT, keycontrolCallback);
    alarm(2);

    for (int i = 0; i < 10; ++i)
    {
        printf("wait...\n");
        sleep(100);
    }

    return 0;
}

void timeoutCallback(int sig)
{
    if (sig == SIGALRM)
        puts("Timeout");
    alarm(2);
}

void keycontrolCallback(int sig)
{
    if (sig == SIGINT)
        puts("CTRL+C pressed");
}