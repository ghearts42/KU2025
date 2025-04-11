#include "list.h"

void printInt(const void *pData)
{
    printf("%d", *(int *)pData);
}

void printDouble(const void *pData)
{
    printf("%f", *(double *)pData);
}

int main(void)
{
    List list1, list2;
    initList(&list1, sizeof(int));
    initList(&list1, sizeof(double));

    int i = 4;
    insertFirstNode(&list1, &i); //[4]
    i = 3;
    insertFirstNode(&list1, &i); //[3, 4]
    i = 2;
    insertFirstNode(&list1, &i); //[1, 3, 4]
    int j = 1;
    i = 2;
    insertNode(&list1, &j, &i); //[1, 2, 3, 4]
    i = 3;
    deleteNode(&list1, &i); //[1, 2, 4]
    printList(&list1, printInt);

    double d = 4.4;
    insertFirstNode(&list2, &d); //[4]
    d = 3.3;
    insertFirstNode(&list2, &d); //[3, 4]
    d = 2.2;
    insertFirstNode(&list2, &d); //[1, 3, 4]
    double f = 1.1;
    d = 2.2;
    insertNode(&list2, &f, &d); //[1, 2, 3, 4]
    d = 3.3;
    deleteNode(&list2, &d); //[1, 2, 4]
    printList(&list2, printDouble);

    cleanupList(&list1);
    cleanupList(&list2);
    return 0;
}