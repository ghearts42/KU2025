import sys

frame = sys._getframe()

abc = int()
abc2 = list()

print("Frame now : ", frame)
print("Code object : ", frame.f_code)
print("Local variable : ", frame.f_locals)
print(frame.__dict__.items())
print(frame.__dict__[__name__])

def main():
    a = 123
    b = [3,4,5]
    main_frame = sys._getframe()
    print("main_frame co name : ", main_frame.f_code.co_name)
    print("localmain)

if __name__ == "__main__":
    main()