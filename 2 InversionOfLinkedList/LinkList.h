#ifndef _LINKLIST_H_
#define _LINKLIST_H_


#include <stdio.h>
#include <stdlib.h>


typedef int DataType;
typedef struct Node
{
    DataType data;
    struct Node *next;
} Node;


Node* CreateEmptyList();

Node* CreateList(DataType *addr, unsigned int n);

void DestroyList(Node *head);

void ListInsert(Node *head, unsigned int index, DataType data);

DataType ListDelete(Node *head, unsigned int index);
void reverseList(Node *head);
void PrintList(Node* head);
#endif
