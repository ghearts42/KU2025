// 값 호출(call by value) 참조 호출(call by reference) 차이 예제
#include <stdio.h>

int f(void);
void f2(int *pResult);

int main(void)
{
    int f1_result = f();
    printf("f() 반환 결과 : %d\n", f1_result); // 값을 복사함

    int f2_result;
    f2(&f2_result);
    printf("f2() 처리 결과 : %d\n", f2_result); // 값의 주소를 참조함
    return 0;
}

int f(void)
{
    return 100;
}

void f2(int *pResult)
{
    *pResult = 100;
}