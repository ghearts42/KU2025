#pragma once

#include <cstdio>
// #include <stdlib.h>
// #include <string.h>

class Node
{
private:
    // // int data;
    struct node *next;
};

class List
{
private:
    Node *ptr;
    int eleSize;
    
public:
    List(int eleSize);
    ~List();
    
    void insertFirstNode(const void *pData);
    void insertNode(const void *prevData, const void *pData);
    void deleteNode(const void *pData);
    
    void printList(const List *pList, void (*print)(const void *));
};
