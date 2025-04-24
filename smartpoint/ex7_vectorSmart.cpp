#include <memory>
#include <vector>
#include <iostream>

using namespace std;

class Data
{
public:
    int value;
    Data(int v) : value(v) {}
};
// C -> Struct와 C++ -> Class
// 구조체는 멤버 함수를 붙일 수 없지만 C++에서의 구조체는 가능하다
// C++에서의 struct는 기본이 public으로 이루어짐 (Class는 private)
//섹스

int main()
{
    vector<shared_ptr<Data>> dataList;
    dataList.push_back(make_shared<Data>(1));
    dataList.push_back(make_shared<Data>(2));
//메모리 관리를 위해 스마트 포인터를 사용함

    // shared_ptr<vector<Data>> dataList2;
    // dataList2->push_back(Data(10));
    // dataList2->push_back(Data(20));

    for (const auto &d : dataList)
        cout << d->value << endl;

    // for (const auto &d : *dataList2)
    //     cout << d->value << endl;

    return 0;
}