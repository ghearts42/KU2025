from urllib import request

def main():
    target = request.urlopen("http://google.com")
    print(target.read())
    
if __name__ == "__main__":
    main()