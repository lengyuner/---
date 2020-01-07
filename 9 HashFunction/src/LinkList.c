#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

LinkList CreateEmptyLinkList()
{
    LinkList list;
    list = (LinkList)malloc(sizeof(struct LinkList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int LinkListFind(LinkList list, int key, int *ret)
{
    Node *p = list->head;
    while (p != NULL) {
        if (p->key == key) {
            *ret = p->value;
            return 1;
        }
        p = p->next;
    }
    return 0;
}

void LinkListAppend(LinkList list, int key, int value)
{
    if (list->head == NULL) {
        list->head = (Node *)malloc(sizeof(Node));
        list->head->key = key;
        list->head->value = value;
        list->head->next = NULL;
        list->tail = list->head;
    }
    else {
        list->tail->next = (Node *)malloc(sizeof(Node));
        list->tail = list->tail->next;
        list->tail->key = key;
        list->tail->value = value;
        list->tail->next = NULL;
    }
}

void PrintLinkList(LinkList list)
{
    Node *p = list->head;
    while (p != NULL) {
        printf("(%d:%d)->", p->key, p->value);
        p = p->next;
    }
    printf("NULL\n");
}

void DestroyLinkList(LinkList list)
{
    Node *pre;
    Node *p = list->head;
    while (p != NULL) {
        pre = p;
        p = p->next;
        free(pre);
    }
    free(list);
}
