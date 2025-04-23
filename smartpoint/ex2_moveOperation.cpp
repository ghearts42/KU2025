#include <iostream>
#include <memory>
using namespace std;

class Myclass
{
public:
    int test_a;
    Myclass()
    {
        cout << "Myclass 생성" << endl;
        test_a = 100;
    }
    ~Myclass() { cout << "Myclass 소멸" << endl; }
};

void useUnique(unique_ptr<Myclass> ptr)
{
    cout << "함수 안에서 값 : " << ptr->test_a << endl;
}

int main()
{
    auto p1 = make_unique<Myclass>(); // 값이 100
    auto p2 = move(p1);

    useUnique(move(p2));

    if (!p1)
        cout << "p1은 nullptr" << endl;
    else
        cout << "p1 소유한 값: " << p1->test_a << endl;
    if (!p2)
        cout << "p2은 nullptr" << endl;
    else
        cout << "p2 소유한 값: " << p2->test_a << endl;

    return 0;
}