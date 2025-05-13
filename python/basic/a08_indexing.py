def main():
    print("hello")
    for i in range(0,5):
        print("hello"[i])
    say_hi = "hello"
    for i in range(0,5):
        print(say_hi[i], end='')
    for c in say_hi:
        print(c, end='')
    print()

    say_hi *= 3

    print(say_hi)
    print(say_hi[5:10])
    print(say_hi[-3:])
    print(say_hi[5:10:2]) # start:end:step 안하요
    print(say_hi[-1::-1]) # 거꾸로 출력!

if __name__ == "__main__":
    main()