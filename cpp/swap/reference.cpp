#include <iostream>
int main()
{
    int a;
    a = 100;
    int &r = a; //레퍼런스는 반드시 초기화하고 사용해야함

    r = 200;
    std::cout << a << std::endl;

    return 0;
}