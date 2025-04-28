#include <fcntl.h> //O_CREAT, O_RDWR 등 파일 제어 옵션 상수들을 사용하기 위한 헤더
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h> //shm_open, mmap, munmap, shm_unlink 등 공유 메모리 함수들을 사용하기 위한 헤더
#include <unistd.h>   //ftruncate 같은 파일 디스크립터 조작 함수 사용.

int main()
{
    int shm_df = shm_open("/myshm", O_CREAT | O_RDWR, 0666); // 공유 메모리 객체를 생성
    if (shm_df == -1)
    {
        perror("shm_open");
        exit(1);
    }
    ftruncate(shm_df, 4096); // 공유 메모리 객체의 size를 4096바이트로 설정 기본적으로 생성된 공유 메모리 크기는 0이기 때문에 반드시 ftruncate()로 사이즈 설정해야 함
    char *shm = mmap(0, 4096, PROT_WRITE | PROT_READ, MAP_SHARED, shm_df, 0);

    if (shm == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }

    strcpy(shm, "Hello shared memory From process 1");

    char temp[10];
    scanf("%s", temp);
    munmap(shm, 4096);

    shm_unlink("/myshm");
    return 0;
}