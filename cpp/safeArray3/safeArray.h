#ifndef SAFE_ARRAY_H
#define SAFE_ARRAY_H
#include "array.h"

// #define ARRAY_SIZE 100
// extern const int ARRAY_SIZE; //cpp에 const int ARRAY_SIZE불러오기

class safeArray : public Array
{
private:

public:
    explicit safeArray(int size = Array::getDefaultArraySize());
    safeArray(const int *pArr, int size);
    safeArray(const safeArray& rhs);
    
    // safeArray() { }
    // safeArray(const safeArray& ) { }
    // ~safeArray(){ }
    safeArray& operator=(const safeArray& );
    // safeArray *operator&() {return this;}
    bool operator==(const safeArray& rhs) const;
    int& operator[](int index);
    const int& operator[] (int index) const;
};

#endif