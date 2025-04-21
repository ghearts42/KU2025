#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    cout << "Insert : " << endl;
    string word;
    vector<int> sizes;
    vector<string> sentence;
    while (word != "0")
    {
        cin >> word;
        sizes.push_back(word.size());
        sentence.push_back(word);
    }
    sort(sizes.begin(), sizes.end()); //정렬
    cout << "shortest word : " << sizes[0] << endl;
    cout << "longest word : " << sizes[sizes.size() - 1] << endl;

    for (auto v : sentence)
    {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}