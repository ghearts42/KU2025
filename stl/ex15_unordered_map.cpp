//표준 입력을 받아서
//단어 별 등장 횟수를 출력하는 프로그램
// unordered map은 해쉬 테이블을 가지고 있어 빠른 접근을 가능하게 한다.
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <string> //string - stream
#include <algorithm>
#include <cctype>

using namespace std;

string clean_word(const string word)
{
    string cleaned;
    for (auto ch : word)
    {
        if (isalpha(ch) || isdigit(ch))
            cleaned += tolower(ch);
    }
    return cleaned;
}

int main(){
    string line;
    getline(cin, line);

    unordered_map<string, int> word_count;
    istringstream iss(line);
    string word;

    while (iss >> word)
    {
        string cleaned = clean_word(word);
        if(!cleaned.empty())
        {
            word_count[cleaned]++;
        }
    }
    for (const auto& [key, value] : word_count)
        cout << key << " : " << value << endl;
}