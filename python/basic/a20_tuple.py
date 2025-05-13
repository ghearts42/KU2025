def afunc():
    a = 10
    b = 20
    return a,b

def main():
    #tuple은 불변 자료형으로 요소값 변경이 불가능하다
    a = tuple()
    c = 123
    b = a,c
    print(type(b))
    
    # swap
    a = 10
    b = 20
    a,b = b,a #(a, b) = (b, a) <- tuple type
    print(a,b)
    print(afunc())
    for ele in afunc():
        print(ele)

if __name__ == "__main__":
    main()