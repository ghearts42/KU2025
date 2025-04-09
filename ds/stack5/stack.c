#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "stack.h"

void initStack(Stack *ps, int size, int eleSize)
{
    // ps->pArr = malloc(sizeof(int) * size);
    ps->pArr = malloc(eleSize * size);
    assert(ps->pArr != NULL);
    ps->eleSize = eleSize;
    ps->size = size;
    ps->tos = 0;
}

void cleanUpStack(Stack *ps)
{
    free(ps->pArr);
}

void push(Stack *ps, const void *pData)
{
    // When full
    assert(ps->tos != ps->size);

    memcpy((unsigned char *)ps->pArr + ps->tos * ps->eleSize, pData, ps->eleSize);
    ++ps->tos;
}

void pop(Stack *ps, void *pData)
{
    // When empty
    assert(ps->tos != 0);

    --ps->tos;

    memcpy(pData, (unsigned char *)ps->pArr + ps->tos * ps->eleSize, ps->eleSize);
}