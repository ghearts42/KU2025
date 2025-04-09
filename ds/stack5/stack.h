// #pragma once
#ifndef STACK_H
#define STACK_H
// #define STACK_SIZE 100
// struct stack
// {
//     int array[100];
//     int tos;
// };
typedef struct stack
{
    // int array[STACK_SIZE];
    void *pArr;
    int eleSize;
    int size;
    int tos;
} Stack;

void initStack(Stack *ps, int size, int eleSize);
void cleanUpStack(Stack *ps);

void push(Stack *ps, const void *pData);
void pop(Stack *ps, void *pData);

#endif