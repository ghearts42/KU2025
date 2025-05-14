# 고정적인 데이터로 100명의 학생을 처리하는 프로그램 2개
# 1. 랜덤한 데이터 생성 후 저장하는 프로그램 (100명을 저장함 이름, 국어, 영어, 수학, 과학 점수 / student.txt로 저장)
# 2. student.txt를 읽어서 클래스를 생성하고 처리하는 프로그램

import random

def make_data():
    hangul = list("김나박이정최곽위황손씹빡톤조무노쌉우띵강재오")
    hangul2 = list("가나다라마바사아자차카타파하근출룡일석오치도포시지독보크야맹호태풍호잉루톤정모칠조팔으로하는수술은뭐든지잘해괵퉁촐택깡막쇠")
    f = open("/home/hjpubuntu22045/korea_c/python/basic/a59_3_student.txt", 'w')
    for i in range(0, 100):
        namelist = random.choice(hangul) + "".join(random.choices(hangul2, k=2))
        scoreK = random.randint(0, 100)
        scoreE = random.randint(0, 100)
        scoreM = random.randint(0, 100)
        scoreS = random.randint(0, 100)
        data = namelist+" "+str(scoreK)+" "+str(scoreE)+" "+str(scoreM)+" "+str(scoreS)+"\n"
        # print(data)
        f.write(data)
    f.close()
    
def main():
    if 
    
if __name__ == "__main__":
    main()