cnt = 0

def fibonacci(n):
    global cnt
    cnt += 1
    if n == 1:
        return 1
    elif n == 2:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)
    
def main():
    print(fibonacci(25))
    print(f"fibonacci 횟수{cnt}")
    
if __name__ == "__main__":
    main()