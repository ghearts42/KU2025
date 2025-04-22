#include <iostream>
using namespace std;

class Adder
{
    public:
    int offset;
    Adder(int o) : offset(o) {};
    int operator()(int x) const { return x + offset; }
};

int main()
{
    double pi = 3.1415926535;
    auto calc = [&pi](int r) -> double
    {
        return pi * r * r;
    };
    cout << "PI : " << pi << endl;
    cout << "면적 : " << calc(3) << endl;

    int sum = 0;
    auto calc2 = [&sum](int x, int y)
    {
        sum = x + y;
    };
    calc2(2,3);
    cout << "합 : " << sum << endl;

    Adder addObject(4);
    cout << addObject(10) << endl;

    return 0;
}