#include <memory>
#include <cstdio>
#include <iostream>

using namespace std;

class FileCloser
{
public:
    void operator()(FILE *fp)
    {
        if(fp)
            cout << "fclose 동작" << endl;
            fclose(fp);
    }
};

void useUnique(unique_ptr<FILE, FileCloser> ptr)
{
    cout << "fp 받아 사용하는 함수" << endl;
}

int main()
{
    auto fp = fopen("/home/hjpubuntu22045/korea_c/stl/student.txt", "r");
    unique_ptr<FILE, FileCloser> filePtr(fp);
    // fclose(fp);
    useUnique(move(filePtr));
    cout << "main 종료" << endl;
    return 0;
}