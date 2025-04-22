#include <array>
#include <iostream>
#include <deque>
#include <list>
#include <set>
#include <unordered_map>

using namespace std;

int main()
{
    array<int, 10> arr = {0,1,2,3,4,5,6,7,8,9};
    for (const auto &x : arr)
        cout << x << " ";
    cout << endl;

    deque<int> dq = {1,2,3};
    dq.push_back(4);
    dq.push_front(0);
    dq.emplace_back(5);
    dq.emplace_front(-1);
    dq.insert(dq.begin() + 3, 2.5);
    
    for (const auto & v : dq)
        cout << v << " ";
    cout << endl;

    dq.pop_back();
    dq.pop_front();
    
    for (const auto & v : dq)
        cout << v << " ";
    cout << endl;
    

    //list insert delete
    list<int> lst = {1,2,3};
    auto it = lst.begin();
    ++it;
    ++it;
    lst.insert(it,3);
    for(const auto& v : lst)
    {
        cout << v << " ";
    }
    cout << endl;

    //set 집합 - 중복 없는 자료, 자동 정렬
    set<int> s = {3,1,2,2,1};
    for (const auto & v : s)
        cout << v << " ";
    cout << endl;
    cout << "s 집합 크기 : " << s.size() << endl;
    
    //unordered_map 해쉬 테이블 기반의 자료 -> 참조가 빠름
    //sha256
    unordered_map<std::string, int> um = {{"apple", 100}, {"banana", 150}, {"mango", 200}};
    for(const auto& [key, val] : um)
    {
        cout << key << " : " << val << endl;
    }
    cout << um["apple"] << endl;
    return 0;
}