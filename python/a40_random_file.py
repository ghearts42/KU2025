import random

def main():
    hangul = list("김나박이정최곽위황손씹빡톤조무노쌉")
    hangul2 = list("가나다라마바사아자차카타파하근출룡톤정모칠조팔으로하는수술은뭐든지잘해괵퉁촐택깡막쇠")
    # with open("data/info.txt","w") as f:
    #     for _ in range(100):
    name = random.choice(hangul) + "".join(random.choices(hangul2, k=2))
    print(name)

if __name__ == "__main__":
    main()