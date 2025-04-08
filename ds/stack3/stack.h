// #pragma once
#ifndef STACK_H
#define STACK_H
#define STACK_SIZE 100
// struct stack
// {
//     int array[100];
//     int tos;
// };
typedef struct stack
{
    int array[STACK_SIZE];
    int tos;
} Stack;

void initStack(Stack *ps);

void push(Stack *ps, int data);
int pop(Stack *ps);

#endif