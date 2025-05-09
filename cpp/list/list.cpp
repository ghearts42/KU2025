#include "list.h"

List::List(int eleSize) // 초기화
{
    //pList->ptr = malloc(sizeof(Node) /*+ eleSize*/);
    this->ptr = new int[eleSize];
    this->ptr->next = NULL;
    this->eleSize = eleSize;
}

List::~List() // malloc free
{
    Node *p = pList->ptr;
    while (p)
    {
        Node *tmp = p;
        p = p->next;
        free(tmp);
    }
}

void insertFirstNode(const void *pData)
{
    Node *p = malloc(sizeof(Node) + pList->eleSize);
    // // p->data = data;
    // memcpy((unsigned char *)p + sizeof(Node), pData, pList->eleSize);
    memcpy(p + 1, pData, pList->eleSize);
    p->next = pList->ptr->next;
    pList->ptr->next = p;
}

void insertNode(const void *prevData, const void *pData)
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

void deleteNode(const void *pData)
{
    Node *p = pList->ptr->next;
    Node *p2 = pList->ptr;
    while (p)
    {
        if (memcmp(p + 1, pData, pList->eleSize) == 0)
        {
            break;
        }
    }
    p = p->next;
    p2 = p2->next;
    if (p)
    {
        p2->next = p->next;
        free(p);
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