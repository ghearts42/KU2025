def print_n_times(*args, **kwargs):
# 이 줄은 'print_n_times'라는 이름의 함수를 정의합니다.
# *args: '애스터리스크(별표) args'는 "arbitrary positional arguments"의 줄임말로, 
#        함수를 호출할 때 개수가 정해지지 않은 여러 개의 위치 인자(positional arguments)를 튜플(tuple) 형태로 받습니다.
#        예를 들어, print_n_times("a", "b", "c")로 호출하면 args는 ("a", "b", "c")가 됩니다.
# **kwargs: '더블 애스터리스크(별표 두 개) kwargs'는 "arbitrary keyword arguments"의 줄임말로,
#           함수를 호출할 때 개수가 정해지지 않은 여러 개의 키워드 인자(keyword arguments)를 딕셔너리(dictionary) 형태로 받습니다.
#           예를 들어, print_n_times(name="홍길동", age=30)으로 호출하면 kwargs는 {'name': '홍길동', 'age': 30}이 됩니다.

    print(type(args))
    # type(args): 'args' 변수의 자료형(type)을 반환합니다. *args로 받은 인자들은 튜플(tuple)이므로, <class 'tuple'>이 출력됩니다.
    # print(...): 반환된 자료형을 화면에 출력합니다.

    print(type(kwargs))
    # type(kwargs): 'kwargs' 변수의 자료형을 반환합니다. **kwargs로 받은 인자들은 딕셔너리(dictionary)이므로, <class 'dict'>가 출력됩니다.
    # print(...): 반환된 자료형을 화면에 출력합니다.

    print(args)
    # 'args' 튜플에 저장된 모든 위치 인자들을 화면에 출력합니다.

    for k, v in kwargs.items():
    # kwargs.items(): 'kwargs' 딕셔너리의 모든 키(key)와 값(value)의 쌍을 가져옵니다. 
    #                 각 쌍은 (키, 값) 형태의 튜플로 반환됩니다.
    # for k, v in ...: 딕셔셔너리의 각 키-값 쌍에 대해 반복문을 실행합니다. 
    #                   첫 번째 반복에서는 첫 번째 키가 'k'에, 해당 값이 'v'에 할당되고, 
    #                   두 번째 반복에서는 두 번째 키-값이 할당되는 식으로 모든 항목에 대해 반복합니다.

        n = kwargs.get("n")
        # kwargs.get("n"): 'kwargs' 딕셔너리에서 'n'이라는 키에 해당하는 값을 가져옵니다.
        #                   만약 'n'이라는 키가 딕셔너리 안에 존재하지 않으면, .get() 메서드는 기본값으로 None을 반환합니다.
        #                   (딕셔너리 접근 시 kwargs['n']과 달리, 키가 없을 때 오류를 발생시키지 않습니다.)
        # n = ...: 가져온 값을 변수 'n'에 할당합니다.
        # 주의: 이 줄은 for 루프 내에 있습니다. 즉, kwargs의 각 항목을 반복할 때마다 'n' 값을 딕셔너리에서 다시 가져옵니다. 
        #       일반적으로 반복 횟수를 지정하는 'n'과 같은 값은 루프 시작 전에 한 번만 가져오는 것이 더 효율적입니다.
        #       또한, 현재 main 함수에서의 호출(`print_n_times(...)`)에는 'n'이라는 키워드 인자가 없으므로, 여기서 `n`은 항상 `None`이 됩니다.

        if n:
        # 변수 'n'이 참(True)으로 평가될 수 있는 값인지 확인합니다.
        # 파이썬에서 None, 0, 빈 문자열 "", 빈 리스트 [], 빈 튜플 (), 빈 딕셔너리 {} 등은 거짓(False)으로 간주됩니다.
        # 그 외의 대부분의 값은 참(True)으로 간주됩니다.
        # 현재 main 함수 호출에서는 'n'이 None이므로, 이 조건은 항상 거짓(False)이 됩니다. 
        # 따라서 이 if 블록 안의 코드는 main 함수에서의 호출로는 실행되지 않습니다.

            for _ in range(n):
            # 만약 'n'이 참(True)이고 숫자라면 (예: n=3), range(n)은 0부터 n-1까지의 숫자 시퀀스를 생성합니다 (예: 0, 1, 2).
            # for _ in ...: 'n'번 반복하는 루프를 실행합니다. 변수명으로 '_' (언더스코어)를 사용하는 것은 
            #                루프 인덱스 값을 사용하지 않을 것이라는 관례적인 표현입니다.
            # 이 루프는 현재 main 함수 호출에서는 실행되지 않습니다.

                print(f"{k} : {v}")
                # f-string (formatted string literal)을 사용하여 문자열을 만듭니다.
                # {k}는 현재 외부 루프의 키 'k'의 값으로, {v}는 현재 외부 루프의 값 'v'의 값으로 대체됩니다.
                # 예를 들어, k가 "a"이고 v가 3이라면 "a : 3"이 출력됩니다.
                # 이 print 문은 'n'번 반복해서 실행됩니다 (만약 if n: 조건이 참이었다면).
                # 이 부분 역시 현재 main 함수 호출에서는 실행되지 않습니다.
    
def main():
# 'main'이라는 이름의 함수를 정의합니다. 프로그램의 주요 실행 로직을 담고 있습니다.

    print_n_times("hi", 123, 3.14, a=3, b=4, n =5, abc="hi")
    # print_n_times 함수를 호출합니다.
    # "hi", 123, 3.14: 이들은 위치 인자(positional arguments)로, 함수 내에서 'args' 튜플에 담깁니다.
    #                  따라서 args는 ("hi", 123, 3.14)가 됩니다.
    # a=3, b=4, c=5, abc="hi": 이들은 키워드 인자(keyword arguments)로, 함수 내에서 'kwargs' 딕셔너리에 담깁니다.
    #                          따라서 kwargs는 {'a': 3, 'b': 4, 'c': 5, 'abc': 'hi'}가 됩니다.
    #                          여기에 'n'이라는 키워드 인자는 전달되지 않았습니다.
    
if __name__ == "__main__":
# 이 스크립트 파일이 직접 실행될 때만 다음 블록의 코드를 실행하도록 하는 파이썬의 관용적인 표현입니다.
# (자세한 설명은 첫 번째 코드 분석의 해당 부분을 참고해주세요.)

    main()
    # 위에서 정의한 'main' 함수를 호출하여 프로그램의 주요 로직을 실행합니다.