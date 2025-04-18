#ifndef ARRAY_H
#define ARRAY_H

// #define ARRAY_SIZE 100
// extern const int ARRAY_SIZE; //cpp에 const int ARRAY_SIZE불러오기


class Array
{
private:
    static const int ARRAY_SIZE; //extern const int ARRAY_SIZE;  public안으로 불러옴 , private로 부르면 외부차단으로 인해 에러 발생
    int *pArr_;
    int size_;

public:
    // extern const int ARRAY_SIZE;  //public안으로 불러옴 , private로 부르면 외부차단으로 인해 에러 발생
    static int getDefaultArraySize();

    // Array(); // Array() {};
    explicit Array(int size = ARRAY_SIZE);  //Array::Array(int size)
    Array(const int *pArr, int size);
    Array(const Array& rhs);     // Array(const Array&) { /*memberwise copy */}
    ~Array();  // ~Array() {};

    Array& operator=(const Array& rhs);   //{/*memberwise copy */ return *this}

    bool operator==(const Array& rhs) const;
    // Array *operator&() {return this;}
    // const Array*operator&() const { return this; }

    int& operator[](int index);
    const int& operator[](int index) const;
    int size() const;
};


#endif