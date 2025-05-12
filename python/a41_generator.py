def test():
    print("함수 호출")
    yield "test"
    
def main():
    print("a")
    test() # return object 만들고 실행은 따로
    
    print("b")
    test()
    print(test())

if __name__ == "__main__":
    main()