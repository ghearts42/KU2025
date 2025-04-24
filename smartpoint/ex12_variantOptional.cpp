//g++ -std=c++17 ex12~.cpp -o ex12~

#include <any>
#include <iostream>
#include <optional>
#include <string>
#include <variant>

using namespace std;

int main()
{
    variant<int, string> data; //데이터를 하나의 메모리에 저장. 타입이 여러가지일 경우
    data = 42;
    cout << get<int>(data) << endl;
    data = string("hello");
    cout << get<string>(data) << endl;

    optional<int> maybeInt; //값이 있을수도 없을수도 있음
    maybeInt = 10;
    if (maybeInt)
        cout << *maybeInt << endl;

    any anything = 123;
    cout << any_cast<int>(anything) << endl;
    anything = string("hi");
    cout << any_cast<string>(anything) << endl;
    anything = 1.1;
    cout << any_cast<double>(anything) << endl;

    return 0;
}