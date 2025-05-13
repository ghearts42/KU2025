import random

def create_student(name, korean, math, english, science):
    return {
        "name" : name,
        "korean" : korean,
        "math" : math,
        "english" : english,
        "science" : science
    }
    
def student_get_sum(student) :
    return student["korean"] + student["math"] + student["english"] + student["science"]

def student_get_avg(student, num) :
    return student_get_sum(student)/num
    
def student_to_string(student, num):
    return f'{student["name"]}\t{student_get_sum(student)}\t{student_get_avg(student, num)}'
    
def main():
    hangul = list("김나박이정최곽위황손씹빡톤조무노쌉")
    hangul2 = list("가나다라마바사아자차카타파하근출룡톤정모칠조팔으로하는수술은뭐든지잘해괵퉁촐택깡막쇠")
    # with open("data/info.txt","w") as f:
    #     for _ in range(100):
    students = [
        create_student(
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