def main():
    abc = str() #str class
    abc2 = "hi" #str class(python)
    print(type(abc))
    print(type(abc2)) #빌드인 클래스는 파이썬에서는 소문자로 시작함
    abc = 4
    print(type(abc))
    abc = 3.14
    print(type(abc))
    abc = [1,2]
    print(type(abc)) #similar to STL vector

if __name__ == "__main__":
    main()