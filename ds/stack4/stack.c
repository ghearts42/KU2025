#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

void initStack(Stack *ps, int size)
{
    ps->pArr = malloc(sizeof(int) * size);
    assert(ps->pArr != NULL);
    ps->size = size;
    ps->tos = 0;
}

void cleanUpStack(Stack *ps)
{
    free(ps->pArr);
}

void push(Stack *ps, int data)
{
    // When full
    // if (ps->tos == ps->size)
    // {
    //     fprintf(stderr, "Stack is full.\n");
    //     exit(1); // 프로그램 비정상 종료
    // }
    assert(ps->tos != ps->size);

    // (*ps).array[(*ps).tos] = data;
    // ++(*ps).tos;
    *(ps->pArr + ps->tos) = data;
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
    return ps->pArr[ps->tos];
}