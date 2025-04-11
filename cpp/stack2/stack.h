#ifndef STACK_H
#define STACK_H

class Stack
{
private: //implementation
    int *pArr;
    int size;
    int tos;
    
public:
    // void initStack(int size);
    Stack(int size);
    // void cleanUpStack();
    ~Stack();
    
    void push(int data);
    int pop();
};

#endif