#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initList(List *pList, int eleSize) // 초기화
{
    pList->ptr = malloc(sizeof(Node) /*+ eleSize*/);
    // pList->ptr->data =
    pList->eleSize = eleSize;

    pList->ptr->next = NULL;
}

void cleanupList(List *pList) // malloc free
{
    Node *ptr = pList->ptr;
    while (ptr)
    {
        Node *tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }
}

void printList(const List *pList, void (*print)(const void *))
{
    Node *p = pList->ptr->next;
    printf("[");
    while (p)
    {
        print(p + 1);
        printf((p->next) ? ", " : "");
        p = p->next;
    }
    printf("]\n");
}

void insertFirstNode(List *pList, const void *pData)
{
    Node *p = malloc(sizeof(Node) + pList->eleSize);
    // // p->data = data;
    // memcpy((unsigned char *)p + sizeof(Node), pData, pList->eleSize);
    memcpy(p + 1, pData, pList->eleSize);
    p->next = pList->ptr->next;
    pList->ptr->next = p;
}

void insertNode(List *pList, const void *prevData, const void *pData)
{
    Node *p = pList->ptr->next;
    while (p)
    {
        if (memcmp(p + 1, prevData, pList->eleSize) == 0)
        {
            break;
        }
        p = p->next;
    }

    if (p)
    {
        Node *tmp = malloc(sizeof(Node) + pList->eleSize);
        // tmp->data = data;
        memcpy(tmp + 1, pData, pList->eleSize);
        tmp->next = p->next;
        p->next = tmp;
    }
}

void deleteNode(List *pList, const void *pData)
{
    Node *ptr = pList->ptr->next;
    Node *ptr2 = pList->ptr;

    while (ptr)
    {
        // if (ptr->data == data)
        if (memcmp(ptr + 1, pData, pList->eleSize) == 0)
            break;

        ptr = ptr->next;
        ptr2 = ptr2->next;
    }

    if (ptr)
    {
        ptr2->next = ptr->next;
        free(ptr);
    }
}
