#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Node
{
    // // int data;
    struct node *next;
};

class List
{
    Node *ptr;
    int eleSize;
};

void initList(List *pList, int eleSize);
void cleanupList(List *pList);

void insertFirstNode(List *pList, const void *pData);
void insertNode(List *pList, const void *prevData, const void *pData);
void deleteNode(List *pList, const void *pData);

void printList(const List *pList, void (*print)(const void *));