import random

class Student:
    def __init__(self, name, korean, math, english, science):
    # cpp에서는 생략 가능하지만 파이썬은 self를 반드시 붙여야함
        self.name = name
        self.korean = korean
        self.math = math
        self.english = english
        self.science = science
    
def student_get_sum(student: Student) :
    return student.korean + student.math + student.english + student.science

def student_get_avg(student:Student, num:int) :
    return student_get_sum(student)/num
    
def student_to_string(student, num):
    return f"{student.name}\t{student_get_sum(student)}\t{student_get_avg(student, num)}"
    
def main():
    hangul = list("김나박이정최곽위황손씹빡톤조무노쌉우띵강재오")
    hangul2 = list("가나다라마바사아자차카타파하근출룡일석오치도포시지독보크야맹호태풍호잉루톤정모칠조팔으로하는수술은뭐든지잘해괵퉁촐택깡막쇠")
    # with open("data/info.txt","w") as f:
    #     for _ in range(100):
    students = [
        Student(
            random.choice(hangul) + "".join(random.choices(hangul2, k=2)),
            random.randint(65, 100),
            random.randint(65, 100),
            random.randint(65, 100),
            random.randint(65, 100),
        )
        for _ in range(50)
    ]
    for student in students:
        print(student_to_string(student, 4))

if __name__ == "__main__":
    main()