#include <stdio.h>

void local(void);
void staticVar(void);
char *global = "전역변수";
int local_count = 1;

int main(void)
{
    printf("main %s\n", global);
    int i;
    for (i = 0; i < 3; i++)
    {
        local();
        staticVar();
    }
    return 0;
}

void local(void)
{
    printf("%s\n", global);
    int count = 1;
    printf("local() 함수가 %d번째 호출되었습니다.\n", local_count);
    local_count++;
}

void staticVar(void)
{
    static int static_count = 1;
    printf("staticVar() 함수가 %d번째 호출되었습니다.\n", static_count);
    static_count++;
}