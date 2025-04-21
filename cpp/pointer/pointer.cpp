#include <iostream>

int main()
{
    int a = 0x12345678;
    // char *p = 
    // char *p = static_cast<char *>(&a); //컴파일 시 형호환 체크 c++은 자료형에 대한 구분이 엄격하므로
    char *p = reinterpret_cast<char *>(&a);

    printf("0x%x\n", *p);

    return 0;
}