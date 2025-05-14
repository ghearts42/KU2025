class Test:
    def __init__(self, name):
        self.name = name
        print(f"{self.name} 생성됨")
        
    def __del__(self):
        print(f"{self.name} 파괴됨")
        
def main():
    a = Test("a")
    b = Test("b")
    c = Test("c")
    print(a,b,c)
    li = [a,b,c]
    del c
    print(li)
    # print(c)
    
if __name__ == "__main__":
    main()