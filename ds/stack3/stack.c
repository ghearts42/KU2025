#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initStack(Stack *ps)
{
    ps->tos = 0;
}

void push(Stack *ps, int data)
{
    // When full
    if (ps->tos == STACK_SIZE)
    {
        fprintf(stderr, "Stack is full.\n");
        exit(1); // 프로그램 비정상 종료
    }

    // (*ps).array[(*ps).tos] = data;
    // ++(*ps).tos;
    ps->array[ps->tos] = data;
    ++ps->tos;
}

int pop(Stack *ps)
{
    // When empty
    if (ps->tos == 0)
    {
        fprintf(stderr, "Stack is empty");
        exit(2);
    }

    // --(*ps).tos;
    // return (*ps).array[(*ps).tos];
    --ps->tos;
    return ps->array[ps->tos];
}