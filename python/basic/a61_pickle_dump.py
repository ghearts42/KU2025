import random
import pickle
from a58_method import Student

def main():
    hangul = list("김나박이정최곽위황손씹빡톤조무노쌉우띵강재오")
    hangul2 = list("가나다라마바사아자차카타파하근출룡일석오치도포시지독보크야맹호태풍호잉루톤정모칠조팔으로하는수술은뭐든지잘해괵퉁촐택깡막쇠")
    with open("/home/hjpubuntu22045/korea_c/python/basic/a61_pickle_dump.pickle","wb") as f:
        for _ in range(100):
            data = Student(
                random.choice(hangul) + "".join(random.choices(hangul2, k=2)),
                random.randint(65, 100),
                random.randint(65, 100),
                random.randint(65, 100),
                random.randint(65, 100),
            )
            pickle.dump(data, f)


if __name__ == "__main__":
    main()