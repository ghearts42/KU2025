#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main()
{
    __pid_t pid = fork();
    int status;
    if (pid == 0)
    {
        return 3;
    }
    else
    {
        pid = fork();
        if (pid == 0)
        {
            exit(7);
        }
        else
        {
            printf("child process ID : %d\n", pid);
            wait(&status);
            if (WIFEXITED(status))
            {
                printf("message from child 1 : %d\n", WEXITSTATUS(status));
            }
            wait(&status);
            if (WIFEXITED(status))
            {
                printf("message from child 2 : %d\n", WEXITSTATUS(status));
            }
            sleep(30);
        }
    }
    if (pid == 0)
    {
        puts("end child process\n");
    }
    else
    {
        puts("end parent process");
    }

    return 0;
}