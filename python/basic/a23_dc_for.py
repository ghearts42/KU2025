def main():
    dict_a = dict()
    list_a = ["AAAA","BBB"]
    dict_b = {1: 1,2: 2,3: 3} #set과 헷갈리지 않도록 주의함
    
    print(type(dict_a), type(dict_b))
    
    a = 'd'
    dict_c = {'a':100, 'b':200, 'c':300, a:400}
    # for i in dict_c:
    #     print(i, dict_c[i], end = " ")
    
    for k,v in dict_c.items():
        print(k,v,end=", ")
    print()
    
    dict_b.update(dict_c)
    print(dict_b)
    
    del dict_b[3]
    print(dict_b)
    del list_a
    # print(list_a)
    print(dict_b.pop(2))
    print(dict_b)       
    
if __name__ == "__main__":
    main()