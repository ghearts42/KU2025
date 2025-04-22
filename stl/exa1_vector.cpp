#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v; //정수에 대한 벡터 v 선언

    v.push_back(1);
    v.push_back(2);
    v.push_back(3); //벡터에 1,2,3 삽입

    for (int i = 0; i < v.size(); i++) //벡터의 모든 원소 출력
    {
        cout << v[i] << " "; //v[i]는 벡터의 i번째 원소
    }
    cout << endl;

    v[0] = 10; //0번째 벡터의 값을 10으로 변경
    int m = v[2]; //m에 3 저장
    v.at(2) = 5; //벡터의 2번째 값을 5로 변경

    for (int i = 0; i < v.size(); i++) //벡터 원소 출력
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// 1 2 3
// 10 2 5