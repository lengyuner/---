#ifndef LINKLIST_H
#define LINKLIST_H


typedef struct Node {
    int key;
    int value;
    struct Node *next;
} Node;

typedef struct LinkList {
    Node *head;
    Node *tail;
} *LinkList;


LinkList CreateEmptyLinkList();

int LinkListFind(LinkList list, int key, int *ret);

void LinkListAppend(LinkList list, int key, int value);

void PrintLinkList(LinkList list);

void DestroyLinkList(LinkList list);


#endif
