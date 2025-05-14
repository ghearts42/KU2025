from dataclasses import dataclass

@dataclass
class Student:
    name : str
    korean : int
    math : int
    
    def get_sum(self):
        return self.korean + self.math
    
def main():
    st1 = Student("baba", 100, 100)
    st2 = Student("keke", 50, 50)
    
if __name__ == "__main__":
    main()