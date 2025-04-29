#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <wait.h>

#define SHM_NAME "/myshm"
#define SEM_NAME "/mysem"
#define SHM_SIZE 128

int main()
{
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SHM_SIZE);
    char *shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    sem_t *sem = sem_open(SEM_NAME, O_CREAT, 06666, 1);

    pid_t pid = fork();
    if (pid == 0)
    {
        sem_wait(sem);
        printf("자식");
        printf("Child read : %s\n", shm);
        sem_post(sem);

        munmap(shm, SHM_SIZE);
        sem_close(sem);
        exit(0);
    }
    if (pid > 0)
    {
        sem_wait(sem);
        printf("부모");
        strcpy(shm, "Hello there parents");
        printf("Parent wrote : %s\n", shm);
        sem_post(sem);

        wait(NULL); // fork 된 다른 프로세서 종료 대기.

        munmap(shm, SHM_SIZE); // 메모리 해제
        close(shm_fd);
        shm_unlink(SHM_NAME); // 언링크

        sem_close(sem); // 세마포어 해제
        sem_unlink(SEM_NAME);
    }

    return 0;
}