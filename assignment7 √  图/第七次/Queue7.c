#include"Queue.h"
/*
Args: 
    * Maxsize: The maxsize of the queue
Return: 
    * Pointer points to a Queue. 
Description:
    * Create an empty queue with capacity of MAXSIZE
*/
PQueue CreatQueue(int Maxsize)
{
	PQueue q;
	q = (PQueue)malloc(sizeof(Queue));
	q->base=(DataType*)malloc(Maxsize*sizeof(DataType));
	q->front=q->rear=0;
	q->maxsize = Maxsize;
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
void DestroyQueue(PQueue q)
{
	free(q->base);
	free(q);
	q = NULL;
}



/*
Args: 
    * q:Pointer points to a queue
Return: 
    * true of false,if you can't insert,you return fasle.Otherwise,you return true.
Description:
    * If the queue is  4 5 6 and x=3, after Insert(Q,x),the queue is 4 5 6 3 
*/
bool Insert(PQueue q,DataType x)
{  
	if(Full(q))
	{
		//printf("队列已满，无法插入");
		return false;
	}
	q->base[q->rear]=x;
	q->rear=(q->rear+1)%q->maxsize;
}



/*
Args:
    * q:Pointer points to a queue
	* x:Pointer points to a memory which can store the number you delete
Return:
    * If the queue is empty,return false.Otherwise, you should return true.
Description:
    * If the queue is  4 5 6, after Delete(Q,x),the queue is 5 6 and x=4 
*/
bool Delete(PQueue q,DataType*x)
{   
	if(Empty(q))
	{
		//printf("队列为空，无法删除");
		return false;
	}
	*x = q->base[q->front];
	q->front=(q->front+1)%q->maxsize;	
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
	if(q->front==q->rear)
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
	if((q->rear+1)%q->maxsize==q->front)
	{
		return true;
	}
	return false;
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

	if(q->rear>=q->front)
	{
		return q->rear-q->front;
		
	}
	return q->maxsize-(q->front-q->rear);
}