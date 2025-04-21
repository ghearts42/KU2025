#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(11);
    v.push_back(111);
    v.push_back(1238);
    // cout << "1st of v : " << v[0] << endl;
    // cout << "2nd of v : " << v[1] << endl;
    // cout << "3rd of v : " << v[2] << endl;
    // vector<int>::iterator it;
    auto it = v.begin() + 2;
    it = v.begin() + 2;
    v.erase(it); //111삭제됨
    v.at(0) = 2; //원소에 접근하여 변경

    //for문쓰기
    for (int i = 0; i < v.size(); ++i)
    cout << i+1 << " of v : " << v[i] << endl;

    return 0;
}