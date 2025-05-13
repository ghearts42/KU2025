def main():
    i = int()
    while i < 10:
        print(f"{i} now")
        i += 1
        
    li = [1,2,3,4,2,4,2]
    
    while 2 in li:
        print("removing")
        li.remove(2)
    print(li)

    string_a = "this is python class"
    while "i" in string_a:
        string_a = string_a.replace("i", "a")
    print(string_a)
    
    for number in li:
        if number > 3:
            continue
        print(number)
    print()
    
    for number in li:
        if number > 3:
            break
        print(number, end = " ")
    print
    
if __name__ == "__main__":
    main()