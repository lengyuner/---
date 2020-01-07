#include "LinkList1.h"


/*
Args: 
    * None.
Return: 
    * Pointer of the head node.
Description:
    * Create an empty linked list with a head node.
    * The "next" field of the head node should point to NULL.
*/
Node* CreateEmptyList()
{
	//Node *head = NULL;
	//return head;
	Node *head = (Node*)malloc(sizeof(Node));
	if (head == NULL)
	{
		printf("空间缓存不足\n");
		return 0;
	}
	head->next = NULL;
	return head;
}


/*
Args:
    * addr: pointer of an array.
    * n: length of the array.
Return:
    * Pointer of the head node.
Description:
    * Initialize a linked list with an array.
*/
Node* CreateList(DataType *addr, unsigned int n)
{
	//Node *head = NULL;
	////Node *p = new Node;// 
	//Node *p;
	//p = (Node*)malloc(sizeof(Node));
	//p->data = n;
	//head = p;
	//p->data = NULL;
	Node *Head = (Node*)malloc(sizeof(Node));
	if (Head == NULL)
	{
		printf("空间缓存不足。");
		return NULL;
	}
	Node *p = Head;
	//printf("\n\n");
	//printf("1");

	for (int i = 0; i < n; i++)
	{

		Node *NewNode = (Node*)malloc(sizeof(Node));
		//printf("2");
		NewNode->data = i;
		//printf(i);
		//printf("3");
		NewNode->next = NULL;
		p->next = NewNode;
		//printf("4");
		p = p->next;
	}
	//Head->data = n;

	//HeadNode->next = NULL;	
	return Head;
}


/*
Args:
    * head: pointer of the head node.
Returns:
    * None
Description:
    * Destroy the linked list.
    * Release all allocated memory.
*/
void DestroyList(Node *head)
{
	Node *p;
	p = head;
	while (p != head)
	{
		p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		free(p);
	}

	p = head;
	free(p);

	//head->data = NULL;
	//head->next = NULL;


}


/*
Args:
    * head: pointer of the head node.
    * index: index of the inserted data.
    * data: the inserted data.
Returns:
    * None.
Description:
    *   If the linked list is "head->3->5->2",
    * when you call (head, 0, 6), the linked 
    * list will be "head->6->3->5->2".
*/
void ListInsert(Node *head, unsigned int index, DataType data)
{
	Node *NewNode;
	NewNode = (Node*)malloc(sizeof(Node));

	if (NewNode == NULL)
	{
		printf("空间缓存不足。");
	}

	NewNode->data = data;
	if (index < 0) 
	{
		printf("指标错误，请输入一个大于等于 0 的指标");
	}	
	if (index == 0)
	{		
		if (head->next == NULL)
		{
			NewNode->next = NULL;
			head->next = NewNode;
		}
		else
		{
			NewNode->next = head->next;
			head->next = NewNode;
		}
	}
	else
	{		
		Node *q = head;
		int j = 0;
		while ((j < index) && (q->next != NULL))
		{
			q = q->next;
			j++;
		}
		if (j == index)
		{
			NewNode->next = q->next;
			q->next = NewNode;
		}
		else
		{
			printf("没有第%d个结点", index);
		}		
	}
}


/*
Args:
    * head: pointer of the head node.
    * index: index of the deleted data.
Returns:
    * The deleted data.
Description:
    *   If the linked list is "head->3->5->2",
    * when you call (head, 2), the linked 
    * list will be "head->3->5".
*/
DataType ListDelete(Node *head, unsigned int index)
{
	DataType DeletedData;
	if (index == 0)
	{
		Node *p = head;
		p = p->next;
		DeletedData = p->data;
		head->next = p->next;
		free(p);
		//head = head->next;
		//free(p);
	}
	else
	{
		Node *p = head;
		int j = 0;
		while ((j < index ) && (p->next != NULL))
		{
			p = p->next;
			j++;
		}
		if (p->next != NULL)
		{
			Node *q = p->next;
			DeletedData = q->data;
			p->next = q->next;
			free(q);
		}
		else
		{
			printf("没有第%d节点", index);
		}

	}
	return DeletedData;
}
