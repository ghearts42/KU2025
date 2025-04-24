//데이터 사이즈가 크면 이동연산을 고려함
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> vec;
    const int N = 100'000;
    string str = "sample text";
    for (int i = 0; i < N; ++i)
    {
        str += "sample text";
    }
    auto start = chrono::high_resolution_clock::now();
    vec.push_back(str); //0.00236471초
    // vec.push_back(move(str)); //5.189e-06초 = 0.000005189초

    // for (int i = 0; i < N; ++i)
    // {
    //     string str = "sample text";
    // }

    auto end = chrono::high_resolution_clock::now();
    cout << "이동 시간 : " << chrono::duration<double>(end - start).count() << "초" << endl;

    return 0;
}