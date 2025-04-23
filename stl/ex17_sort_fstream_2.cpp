#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Student
{
private:
    string name_;
    vector<int> scores_;

public:
    Student(const string&name, const vector<int> scores):name_(name), scores_(scores){}
    int totalScore() const
    {
        return accumulate(scores_.begin(), scores_.end(),0);
    }
    int averageScore() const
    {
        return totalScore() / scores_.size();
    }
    void print() const
    {
        cout << "name : " << name_ << endl;
        cout << "score : ";
        for (const auto &v : scores_)
        {
            cout << v << " ";
        }
        cout << endl;
        cout << "total : " << totalScore() << endl;
        cout << "average : " << averageScore() << endl;
        cout << "--------------------------------------------------------------------" << endl;
    }
};

int main()
{
    ifstream file("/home/hjpubuntu22045/korea_c/stl/student.txt");
    vector<Student> student;

    string line, name;
    vector<int> scores;
    int score;

    while(getline(file, line))
    {
        istringstream iss(line);
        iss >> name;
        while (iss >> score)
        {
            scores.push_back(score);
        }
        student.emplace_back(name, scores);
        scores.clear();
    }
    file.close();
    
    sort(student.begin(), student.end(), [](const Student &a, const Student &b)
    { return a.averageScore() < b.averageScore(); });

    //partition
    auto fail_boud = partition(student.begin(), student.end(), [](const Student &st){return st.averageScore() < 0;});
    cout << (*fail_boud).averageScore() << endl;
    vector<Student> fail_students(student.begin(),fail_boud);
    vector<Student> successs_students(fail_boud, student.end());

    for(const auto& student : student)
        student.print();

    cout << "합격 : " << endl;
    for (const auto &student : successs_students)
        student.print();

    //merge
    vector<Student> merge_student;
    merge(fail_students.begin(), fail_students.end(), successs_students.begin(), successs_students.end(),back_inserter(merge_student));
    cout << "Merged vector" << endl;
    for (const auto &student : merge_student)
        student.print();
    
    return 0;
}