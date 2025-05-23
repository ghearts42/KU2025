#include "data_process.hpp"
#include <iostream>

using namespace std;

int main()
{
    vector<string> words = {"apple", "ant", "banana", "bear", "cat"};
    DataProcessor processor(words);

    auto sorted = processor.sort_by_length();
    cout << "original sequence : " << endl;
    for (const auto &word : processor.data_)
        cout << word << endl;

    cout << "Sorted by length : " << endl;
    for (const auto &word : sorted)
        cout << word << endl;
    
    cout << "Filtered by prefix : " << endl;
    auto filtered = processor.filter_by_prefix("b");
    for (const auto &word : filtered)
        cout << word << endl;
    
    int min_length = 4;
    auto cout_long = [=]() mutable
    {
        int count = 0;
        for (const auto& word: words)
        {
            if (word.length() >= min_length)
            {
                count++;
            }
        }
        min_length++;
        return count;
    };
    cout << "words with length >= 4 : " << cout_long() << endl;
    cout << "After mutable change, min_length : " << min_length << endl;

    return 0;
}