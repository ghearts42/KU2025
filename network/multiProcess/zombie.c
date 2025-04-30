#include <stdio.h>
#include <unistd.h>

int main()
{
    __pid_t pid = fork();
    if (pid == 0)
    {
        puts("child");
    }
    else
    {
        printf("child process ID : %d\n", pid);
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