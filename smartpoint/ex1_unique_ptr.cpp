#include <iostream>
#include <memory>

using namespace std;

class Myclass{
    public:
    int test_a;
    Myclass()
    {
        cout << "Myclass 생성" << endl;
        test_a = 100;
    }
    ~Myclass()
    {
        cout << "Myclass 소멸" << endl;
    }
};

int main()
{
    auto ptr = make_unique<Myclass>();
    ptr->test_a = 100;
    cout << ptr->test_a << endl;
    return 0;
}