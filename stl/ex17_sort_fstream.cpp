#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Student
{
public:
    string name;
    int sub1;
    int sub2;
    int sub3;
    int sub4;
    int sub5;
    int totalScore() const
    {
        return sub1 + sub2 + sub3 + sub4 + sub5;
    }
    void print() const
    {
        cout << "name : " << name << endl;
        cout << "score : " << sub1 << " "<< sub2 << " " << sub3 << " " << sub4 << " " << sub5 << endl;
        cout << "total : " << totalScore() << endl;
        cout << "--------------------------------------------------------------------" << endl;
    }
};

int main()
{
    ifstream file("/home/hjpubuntu22045/korea_c/stl/student.txt");
    vector<Student> student;

    string name;
    int s1, s2, s3, s4, s5;

    while(file >> name >> s1 >> s2 >> s3 >> s4 >> s5)
    {
        student.push_back({name, s1, s2, s3, s4, s5});
    }
    file.close();
    for (const auto &student : student)
        cout << student.name << " ";
    cout << endl;
    
    sort(student.begin(), student.end(), [](const Student &a, const Student &b) {return a.totalScore() < b.totalScore();});

    for(const auto& student : student)
        student.print();

    return 0;
}