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

using namespace std;

class DataBase {
private:
    unordered_map<int, shared_ptr<string>> data; //Base data
    mutable shared_mutex mutexReadWriteLock; //lock

public:
    // Insert Data
    void insert(int key, const string& value) {
        unique_lock lock(mutexReadWriteLock); // write lock
        data[key] = make_shared<string>(value);
        cout << "Inserted key: " << key << endl;
        cout << "Inserted value: " << value << endl;
    }

    // Search Data
    shared_ptr<string> find(int key) const {
        shared_lock lock(mutexReadWriteLock); // read lock
        auto it = data.find(key);
        if (it != data.end()) {
            return it->second;
        }
        return nullptr;
    }

    // Delete Data
    void remove(int key) {
        unique_lock lock(mutexReadWriteLock); // write lock
        size_t erased = data.erase(key);
        if (erased > 0)
            cout << "Removed key: " << key << endl;
        else
            cout << "Key not found: " << key << endl;
    }
};

int main() {
    DataBase db;
    string command;

    cout << "DB Engine" << endl;
    cout << "Select" << endl;
    cout << "1. insert\n2. find\n3. remove\n4. exit" << endl;

    while (true) {
        cout << "Task : ";
        cin >> command;

        if (command == "1" || command == "insert")
        {
            int key;
            string value;
            cout << "Enter key (int): ";
            cin >> key;
            cout << "Enter value (string): ";
            cin.ignore(); // fflush
            getline(cin, value);
            db.insert(key, value);
        }
        else if (command == "2" || command == "find")
        {
            int key;
            cout << "Enter key (int): ";
            cin >> key;
            auto result = db.find(key);
            if (result)
                cout << "Found: " << *result << endl;
            else
                cout << "Key not found.\n";
        }
        else if (command == "3" || command == "remove")
        {
            int key;
            cout << "Enter key (int): ";
            cin >> key;
            db.remove(key);
        }
        else if (command == "4" || command == "exit")
        {
            cout << "Exiting program.\n";
            break;
        }
        else
        {
            cout << "Unknown command.\n";
        }
    }

    return 0;
}