import time

def main():
    print(time.asctime())
    print(time.time())
    print(time.clock_gettime_ns(1))
    
    ptime = time.time()
    cnt = int()
    while time.time() < ptime + 5:
        cnt += 1
        
    print(f"this computer can count {cnt} per 5 sec")

if __name__ == "__main__":
    main()