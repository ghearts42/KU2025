#include <cstdio>
// #include <stdlib.h>
#include <cassert>
#include "stack.h"

Stack::Stack(int size)
{
    // this->pArr = (int *)malloc(sizeof(int) * size);
    this->pArr = new int[size];
    assert(this->pArr);

    this->size = size;
    this->tos = 0;
}

Stack::~Stack()
{
    // free(this->pArr);
    delete [] this->pArr;
}

void Stack::push(int data)
{
    // When full
    // if (this->tos == this->size)
    // {
    //     fprintf(stderr, "Stack is full.\n");
    //     exit(1); // 프로그램 비정상 종료
    // }
    assert(this->tos != this->size);

    // (*ps).array[(*ps).tos] = data;
    // ++(*ps).tos;
    *(this->pArr + this->tos) = data;
    ++this->tos;
}

int Stack::pop()
{
    // When empty
    // if (this->tos == 0)
    // {
    //     fprintf(stderr, "Stack is empty");
    //     exit(2);
    // }

    // --(*ps).tos;
    // return (*ps).array[(*ps).tos];
    --this->tos;
    return this->pArr[this->tos];
}