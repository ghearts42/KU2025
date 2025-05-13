def main():
    f = open("data/text.txt","w")
    f.write("hello, Python Programming")
    #표준 IO 함수 fputs fprintf
    f.close()
    with open("data/text.txt","a",encoding="utf-8") as f:
        f.write("hello Python 2nd input")

if __name__ == "__main__":
    main()