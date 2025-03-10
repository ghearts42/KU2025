#include <stdio.h>

int main(void)
{
    int i = 100;
    double d = 3.141592;

    void *p;
    // p로 i 가라키기
    p = &i;
    printf("p의 주소값 : %p\n", p);
    printf("*p의 값 : %d\n", *(int *)p);

    p = &d;
    //*p = 563.3566 와 같이 void포인터의 역참조는 불가능하다.
    *(double *)p = 563.3566;
    printf("p의 주소값 : %p\n", p);
    printf("*p의 값 : %f\n", *(double *)p);

    return 0;
}