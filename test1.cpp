#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> test = {12,6,3,2,1};

    for (int cake:test)
        cout << "걍해 : " << cake << endl;
    
    int sum = 0;

    for (auto i:test)
        sum += i;

    cout << "sum : " << sum << endl;

    return 0;
}