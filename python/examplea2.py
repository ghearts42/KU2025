#섭씨화씨 변환 input -> casting -> 연산 -> 출력
def main():
    bo = True
    while True:
        var = input("숫자 입력 : ")
        if var.isdigit():
            cen = float(var)
            fer = cen*1.8 + 32
            print("섭씨", cen, "은 화씨 ", fer)
        elif var == "exit":
            exit()
        else:
            bo = False
            print("숫자입력")

if __name__ == "__main__":
    main()