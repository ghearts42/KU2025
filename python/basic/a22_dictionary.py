def main():
    dict_a = dict()
    dict_b = {1: 1,2: 2,3: 3} #set과 헷갈리지 않도록 주의함
    
    print(type(dict_a), type(dict_b))
    
    a = 'd'
    dict_c = {'a':100, 'b':200, 'c':300, a:400}
    print(dict_c['a'])
    dict_c['d'] = 500 #데이터 덮어씌움
    print(dict_c['d'])
    dict_c['e'] = 600
    print(dict_c['e'])

if __name__ == "__main__":
    main()