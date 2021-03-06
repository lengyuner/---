#include"Queue.h"
/*
Args: 
    * Maxsize: The maxsize of the queue
Return: 
    * Pointer points to a Queue. 
Description:
    * Create an empty queue with capacity of MAXSIZE
*/
PQueue CreatQueue(int maxsize)
{
	PQueue q;
	q = (PQueue)malloc(sizeof(PQueue));
	q->base = (DataType*)malloc((maxsize + 1) * sizeof(DataType));
	q->front = 0;
	q->rear = 0;
	if (q->maxsize == 0)
	{
		q->base[maxsize] = 1;
	}
	else
	{
		q->base[q->rear + 1] = 0;
	}
	q->maxsize = maxsize;
	return q;
}



/*
Args: 
    * q:Pointer points to a queue
Return: 
    * None
Description:
    * Destroy the queue you have created,or free the memory you allocated when you creat the queue.And let q->base=NULL.
*/
void DestroyQueue(PQueue* q)
{
	//free(q->base);
	free(q);
	q = NULL;
}



/*
Args:
* q:Pointer points to a queue
Return:
* true of false,if you can't insert,you return fasle.Otherwise,you return true.
Description:
* If the queue is  4 5 6 and x=3, after InsertRight(Q,x),the queue is 4 5 6 3
*/
bool InsertRight(PQueue q, DataType x)
{
	if (Full(q))
	{
		//printf("队列已满，无法插入");
		return false;
	}
	q->rear = (q->rear + 1) % q->maxsize;
	q->base[q->rear] = x;
	//if (Length)		
	Full(q);
	return true;
}



/*
Args:
* q:Pointer points to a queue
Return:
* true of false,if you can't insert,you return fasle.Otherwise,you return true.
Description:
* If the queue is  4 5 6 and x=3, after InsertLeft(Q,x),the queue is 3 4 5 6
*/
bool InsertLeft(PQueue q, DataType x)
{
	if (Full(q))
	{
		//printf("队列已满，无法插入");
		return false;
	}
	q->base[q->front] = x;
	q->front = (q->front - 1 + q->maxsize) % q->maxsize;
	Full(q);
	return true;
}



/*
Args:
* q:Pointer points to a queue
* x:Pointer points to a memory which can store the number you delete
Return:
* If the queue is empty,return false.Otherwise, you should return true.
Description:
* If the queue is  4 5 6, after DeleteRight(Q,x),the queue is 4 5 and x=6
*/
bool DeleteRight(PQueue q, DataType*x)
{
	if (Empty(q))
	{
		//printf("队列为空，无法删除");
		return false;
	}
	*x = q->base[q->rear];
	q->rear = (q->rear - 1 + q->maxsize) % q->maxsize;
	Full(q);
	return true;
}



/*
Args:
* q:Pointer points to a queue
* x:Pointer points to a memory which can store the number you delete
Return:
* If the queue is empty,return false.Otherwise, you should return true.
Description:
* If the queue is  4 5 6, after DeleteLeft(Q,x),the queue is 5 6 and x=4
*/
bool DeleteLeft(PQueue q, DataType*x)
{
	if (Empty(q))
	{
		//printf("队列为空，无法删除");
		return false;
	}
	*x = q->base[q->front];
	q->front = (q->front + 1) % q->maxsize;
	return true;
}



/*
Args:
	* q:Pointer points to a queue
Return:
	* If the queue is empty,return true.Otherwise, you should return false.
Description:None
*/
bool Empty(PQueue q)
{

	//if (q->front == q->rear-1)
	if (Length(q) == 0)	
	{
		return true;
	}
	return false;
}



/*
Args:
	* q:Pointer points to a queue
Return:
	* If the queue is full,return true.Otherwise, you should return false.
Description:None
*/
bool Full(PQueue q)
{
	if ((q->rear + 1) % q->maxsize == q->front)
	{
		q->base[q->maxsize] = 1;
		return true;
	
	}
	else
	{
		q->base[q->maxsize] = 0;
		return false;
	}
}



/*
Args:
	* q:Pointer points to a queue
Return:
	* Return the number of data the queue has.
Description:Node
*/
int  Length(PQueue q)
{
	if (q->rear >= q->front)
	{
		return q->rear - q->front;
	}
	printf("%d\n", q->maxsize - (q->front - q->rear));
	return q->maxsize - (q->front - q->rear);
}












