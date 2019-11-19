#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"

/*
* args:
    m: length of hash table
    p: used in hash function
* return:
    table: hash table
* description:
    None.
*/
HashTable CreateEmptyHashTable(int m, int p)
{
	//LinkList *base;
	//int m;
	//int p;
	HashTable q;
	q = (HashTable)malloc(sizeof(struct HashTable));

	LinkList *link_list;
	link_list = (LinkList*)malloc(m * sizeof(struct LinkList));
	for (int i = 0; i < m; i++)
	{
		link_list[i] = CreateEmptyLinkList();
	}
	q->base = link_list;
	q->m = m;
	q->p = p;
	return q;
}

/*
args:
    table: hash table
    key: key of data
    value: value of data
return:
    None
description:
    None.
*/
void HashTableInsert(HashTable table, int key, int value)
{
	//LinkListAppend(LinkList list, int key, int value)
	int m, p;
	m = table->m;
	p = table->p;
	//LinkList *link_list;
	int k;
	k = key % p;
	//link_list = table->base[k];
	LinkListAppend(table->base[k], key, value);

	//printf("(%d:%d)->", key, value);

	//key  是惟一的
	//value 不一定是？我也不知道啊
}

/*
args:
    table: hash table
    key: key of data
    ret: pointer to save value
return:
    bool: wether to find the key
description:
    if the key is found, the value is stored in ret and 
    returns 1, otherwise it returns 0.
*/
int HashTableFind(HashTable table, int key, int *ret)
{
	int k;
	int p = table->p;
	k = key % p;
	//LinkListFind(LinkList list, int key, int *ret)
	int find;
	find = LinkListFind(table->base[k], key, ret);
	//printf("%d——", ret);
	return find;

	//return LinkListFind(table->base[k], key, &ret);
}

/*
args:
    table: hash table
return:
    None
description:
    None.
*/
void DestroyHashTable(HashTable table)
{
	free(table);
	table = NULL;
}

/*
args:
    table: hash table
return:
    None
description:
    None.
*/
void PrintHashTable(HashTable table)
{
    int i;
    for (i = 0; i < table->m; ++i) {
        printf("%d: ", i);
        PrintLinkList(table->base[i]);
    }
}
