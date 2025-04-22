#include <iostream>
#include "processor.hpp"

using namespace std;

constexpr int factorial(int n){
    return n <= 1 ? 1 : n * factorial(n - 1);
}

int main(){
    //constexpre test
    constexpr int fact = factorial(5);
    cout << "Factorial 5 :" << fact << endl;

    vector<string> input = {"hello","","world"};
    Processor proc(input);

    auto transformed = proc.transform();
    cout << "transformed 데이터 : " << endl;
    for (const auto& s : transformed)
        cout << s << endl;

    cout << "Compute Tests : " << endl;
    cout << "Int 10 : " << proc.compute(10) << endl;
    cout << "Float 10.0 : " << proc.compute(10.0) << endl;
    cout << "String \"test\": " << proc.compute("test") << endl;

    //nullptr 테스트
    string *ptr = nullptr;
    cout << "Pointer is : " << (ptr == nullptr ? "null" : "non-null") << endl;
    string a = "Non nullptr";
    ptr = &a;
    cout << "Pointer is : " << (ptr == nullptr ? "null" : "non-null") << endl;
    return 0;
}