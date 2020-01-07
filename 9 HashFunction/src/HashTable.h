#ifndef HASHTABLE_H
#define HASHTABLE_H


#include "LinkList.h"


typedef struct HashTable {
    LinkList *base;
    int m;
    int p;
} *HashTable;


HashTable CreateEmptyHashTable(int m, int p);

void HashTableInsert(HashTable table, int key, int value);

int HashTableFind(HashTable table, int key, int *ret);

void PrintHashTable(HashTable table);

void DestroyHashTable(HashTable table);


#endif
