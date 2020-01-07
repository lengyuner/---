#ifndef _QUEUE_H_
#define _QUEUE_H_
#define MAXSIZE 11
typedef int bool;
#define true 1
#define false 0

#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct queue
{
	DataType* base;
	int front;
	int rear;
	int maxsize;
}Queue,*PQueue;

PQueue CreatQueue(int maxsize);
void DestroyQueue(PQueue q);
bool Insert(PQueue q,DataType x);
bool Delete(PQueue q, DataType*x);
bool Empty(PQueue q);
bool Full(PQueue q);
int Length(PQueue q);



#endif