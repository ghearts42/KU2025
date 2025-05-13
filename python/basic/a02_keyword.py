import keyword

def main():
    print(keyword.kwlist)

#이 파일이 실행 될 때만 main()이 실행되도록 하는 코드
#import하더라도 main()은 실행되지 않음
if __name__ == "__main__":
    main()