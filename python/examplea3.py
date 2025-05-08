#문자열 입력으로 단어 카운트 해서 결과 출력

def main():
    sen = input("문장 입력 : ")
    word = input("찾을 단어 : ")
    count = 0
    split_sen = sen.split()
    for i in range(len(split_sen)):
        if word == split_sen[i]:
            count = count + 1
    print("단어 개수 :", count)
    

if __name__ == "__main__":
    main()