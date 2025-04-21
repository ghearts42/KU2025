#include <iostream>
#include <string>
#include <vector>

using namespace std;
// using std::cout;
// using std::endl;

int main()
{
    vector<string> sv;
    string name;

    cout << "Insert 5 names" << endl;
    for (int i = 0; i < 5; ++i)
    {
        cout << i + 1 << ">>";

        getline(cin,name);
        sv.push_back(name);
    }
    name = sv.at(0);
    for (int i = 0; i < sv.size(); ++i)
    {
        if (name < sv[i]) //string 비교 연산자 오버라이디잉디링리ㅣㄹ리이리링
        name = sv[i];
    }
    cout << "last name : " << name << endl;
    return 0;
}