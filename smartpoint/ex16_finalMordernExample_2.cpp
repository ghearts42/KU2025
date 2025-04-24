//STL과 스마트포인터 사용하여 데이터베이스 엔진 만들기
//스마트 포인터 활용 shared_ptr, unique_ptr
//쓰레드 활용 multithread, mutex, atomic >> 내부 동기화 위한 락 구조 설계
//데이터 삽입 insert(key(int), value(string));
//데이터 검색 find(key);
//데이터 삭제 remove(key);
//클래스명 : class DataBase
// 저장용 컨테이너는 참조에 특화되도록 unordered_map
// //컬럼 추가(타입 정하기)

#include <iostream>
#include <memory>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

using namespace std;

class DataBase
{
private:
    unordered_map<int, shared_ptr<string>> db;
    //map : 각 노드가 key와 value로 이루어진 트리
    //unordered로 사용하면 해쉬 테이블로 구현하므로 더 빠름
    mutable shared_mutex mtx;
    //한번에 한 thread에서만 뮤텍스의 사용권한을 부여하기 위함

public:
    void insert(int key, const string &value)
    {
        unique_lock lock(mtx);
        //쓰기 작업이라 unique_lock 사용
        db[key] = make_shared<string>(value);
        //make_shared로 힙에 문자열 동적 할당하고 shared_ptr로 관리
        //해당 키에 값 저장
    }
    shared_ptr<string> find(int key) const
    {
        shared_lock lock(mtx);
        // 읽기 작업이므로 shared_lock 사용 (여러 스레드 동시 읽기 가능)
        auto it = db.find(key);
        return (it != db.end()) ? it->second : nullptr;
        // key 있으면 해당 값의 포인터 리턴, 없으면 nullptr
    }
    void remove(int key)
    {
        unique_lock lock(mtx);
        db.erase(key);
    }
    void printAll() const
    {
        shared_lock lock(mtx);
        for (const auto &[key, value] : db)
        {
            cout << key << " : " << *value << endl;
        }
    }
};

void threadTask(DataBase &db, int id)
{
    for (int i = 0; i < 5; ++i)
    {
        db.insert(id * 10 + i, "Data from main" + to_string(id));
        this_thread::sleep_for(50ms);
    }
}

int main()
{
    DataBase db;
    vector<thread> threads;
    for (int i = 0; i < 20; ++i)
        threads.emplace_back(threadTask, ref(db), i);
    // db.remove(4);
    // db.remove(8);
    cout << "find 3 : " << db.find(3) << endl;
    // cout << "find 4 : " << db.find(4) << endl;
    for (auto &t : threads)
        t.join();
    db.printAll();
    return 0;
}