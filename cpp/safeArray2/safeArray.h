#ifndef SAFE_ARRAY_H
#define SAFE_ARRAY_H
#include "array.h"


// #define ARRAY_SIZE 100
// extern const int ARRAY_SIZE; //cpp에 const int ARRAY_SIZE불러오기

template <typename T>
class safeArray : public Array<T>
{
private:

public:
    explicit safeArray(int size = Array<T>::getDefaultArraySize());
    safeArray(const T *pArr, int size);
    safeArray(const safeArray<T>& rhs);
    
    // safeArray() { }
    // safeArray(const safeArray& ) { }
    // ~safeArray(){ }
    safeArray<T>& operator=(const safeArray<T>& );
    // safeArray *operator&() {return this;}
    bool operator==(const safeArray<T>& rhs) const;
    virtual T& operator[](int index);
    virtual const T& operator[] (int index) const;
};

#include <cassert>

template <typename T>
safeArray<T>::safeArray(int size)
: Array<T>(size)
{
    
}

template <typename T>
safeArray<T>::safeArray(const T *pArr, int size)
: Array<T>(pArr, size)
{
    
}

template <typename T>
safeArray<T>::safeArray(const safeArray<T>& rhs)
: Array<T>((Array<T>)rhs)
{
    
}

template <typename T>
safeArray<T>& safeArray<T>::operator=(const safeArray<T>& rhs)
{
    if (this != &rhs) {
        this->Array<T>::operator=((Array<T>)rhs);
    }

    return *this;
}

template <typename T>
bool safeArray<T>::operator==(const safeArray<T>& rhs) const
{
    return this->Array<T>::operator==((Array<T>)rhs);
}

template <typename T>
T& safeArray<T>::operator[](int index)
{
    assert(index >= 0 && index < this->size());
    return this->Array<T>::operator[](index);
}

template <typename T>
const T& safeArray<T>::operator[](int index) const
{
    assert(index >= 0 && index < this->Array<T>::size());
    return this->Array<T>::operator[](index);
}

#endif