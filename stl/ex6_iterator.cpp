#include <iostream>
#include <vector>

using namespace std;

// class A:
// public:
//     class B :

int main()
{
    vector<int>::iterator it;
    vector<int> test_vector = {1,2,3,4,5,6};
    for (vector<int>::iterator it = test_vector.begin(); it != test_vector.end(); ++it)
    {
        cout << *it << endl;
    }
    // iterator가 정의 -begin(), end()
    // *it 역참조 가능해야 함.
    for (auto v : test_vector) //모던 c++ 
    {
        cout << v << endl;
    }
    for (auto &v : test_vector) //컨테이너의 값을 변경 
    {
        cout << v << endl;
    }
    for (const auto &v : test_vector) //메모리에 대해 효율적인 참고
    {
        cout << v << endl;
    }

    return 0;
}