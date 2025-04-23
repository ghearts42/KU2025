// 학생의 이름과 점수를 저장한 클래스로 벡터를 이용하여 정렬하는 프로그램
// 정렬 기준 = 내림차순(높은 점수가 앞으로 오도록) 점수가 같다면 이름을 오름차순으로 정렬
// algorithm에서는 sort or stable_sort
// 데이터는 1000.txt 에서 읽어오도록
// 학점은 grade -> A > 90, B > 80, C > 70, D > 60, F > 50
// sort_fstream2.cpp 참고

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
    Student(const string& name, const vector<int>& scores) : name_(name), scores_(scores) {}

    int totalScore() const {
        return accumulate(scores_.begin(), scores_.end(), 0);
    }

    int averageScore() const {
        return totalScore() / scores_.size();
    }

    string getGrade() const {
        int avg = averageScore();
        if (avg >= 90)
        {
            return "A";
        }
        else if (avg >= 80)
        {
            return "B";
        }
        else if (avg >= 70)
        {
            return "C";
        }
        else if (avg >= 60)
        {
            return "D";
        }
        else
        {
            return "F";
        }
    }

    void print() const {
        cout << "이름: " << name_ << "\n점수: ";
        for (const auto& score : scores_)
            cout << score << " ";
        cout << "\n평균: " << averageScore() << " | 학점: " << getGrade() << "\n";
        cout << "---------------------------------------------\n";
    }

    const string& getName() const {
        return name_;
    }
};

int main()
{
    ifstream file("/home/hjpubuntu22045/korea_c/stl/student.txt");
    if (!file.is_open()) {
        cerr << "파일을 열 수 없습니다.\n";
        return 1;
    }

    vector<Student> students;
    string line, name;
    vector<int> scores;
    int score;

    while (getline(file, line))
    {
        istringstream iss(line);
        iss >> name;
        while (iss >> score)
            scores.push_back(score);
        students.emplace_back(name, scores);
        scores.clear();
    }
    file.close();

    sort(students.begin(), students.end(),
        [](const Student& a, const Student& b)
    {
        if (a.averageScore() == b.averageScore())
            return a.getName() < b.getName(); // 이름 오름차순
        return a.averageScore() > b.averageScore(); // 평균 점수 내림차순
    });

    for (const auto& student : students)
        student.print();

    return 0;
}
