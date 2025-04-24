#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter = 0;

mutex mtx;

void increament()
{
    for (int i = 0; i < 1000; ++i)
    {
        lock_guard<mutex> lock(mtx);
        ++counter;
    }
}

int main()
{
    thread t1(increament);
    thread t2(increament);

    //exection

    t1.join(); //t1에서 실행되는 상황이 끝날때 대기
    t2.join(); //t2에서 실행된는 상황이 끝날때 대기

    cout << "최종 카운터 : " << counter << endl;
}