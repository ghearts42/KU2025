#include <cassert>
#include "safeArray.h"

safeArray::safeArray(int size)
: Array(size)
{
    
}

safeArray::safeArray(const int *pArr, int size)
: Array(pArr, size)
{
    
}

safeArray::safeArray(const safeArray& rhs)
: Array((Array)rhs)
{
    
}

safeArray& safeArray::operator=(const safeArray& rhs)
{
    if (this != &rhs) {
        this->Array::operator=((Array)rhs);
    }

    return *this;
}

bool safeArray::operator==(const safeArray& rhs) const
{
    return this->Array::operator==((Array)rhs);
}

int& safeArray::operator[](int index)
{
    assert(index >= 0 && index < this->size());
    return this->Array::operator[](index);
}

const int& safeArray::operator[](int index) const
{
    assert(index >= 0 && index < this->size());
    return this->Array::operator[](index);
}