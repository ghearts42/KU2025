#include <memory>

using namespace std;

class B;

class A
{
    public:
        shared_ptr<B> b_ptr;
};

class B
{
    public:
        shared_ptr<A> a_ptr;
};

int main()
{
    auto a = make_shared<A>();
    auto b = make_shared<B>();

    a -> b_ptr = b;
    b -> a_ptr = a;

    return 0;
}