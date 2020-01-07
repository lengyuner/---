#include "LinkList.h"


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
	Node *Head = (Node*)malloc(sizeof(Node));
	if (Head == NULL)
	{
		printf("空间缓存不足。");
		return NULL;
	}
	Node *p = Head;
	for (int i = 0; i < n; i++)
	{
		Node *NewNode = (Node*)malloc(sizeof(Node));
		NewNode->data = addr[i];
		NewNode->next = NULL;
		p->next = NewNode;
		p = p->next;
	}
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

	/*
	Node *p;
	Node *q;	
	while (head->next != NULL) 
	{
		p = head->next;
		q = head;
		while (p->next != NULL)
		{
			p = p->next;
			q = q->next;
		}			
		free(p);		
		q->next = NULL;
	}
	p = head;
	free(head);
	*/
	//head->next = NULL;
	//head->data = NULL;
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
    *   If the linked list is "head->3->5->1",
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
	}
	else
	{
		Node *p = head;
		int j = 0;
		while ((j < index) && (p->next != NULL))
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

/*
Args:
* head: pointer of the head node.
Returns:
* None
Description:
	* Reverse the linked list.
	*	If the linked list is "head->3->5->2",
	* when you call reverseList(head), the linked
	* list will be "head->2->5->3".
*/
void reverseList(Node *head)
{
	if (head->next == NULL)
	{
		printf("the linked list is empty.\n");
		return 0;
	}
	else 
	{
		Node *p;
		Node *q;
		int i, j, k, len;
		p = head;
		len = 0;
		while (p->next != NULL)
		{
			p = p->next;
			len++;
		}
		p = head;
		Node *temp = (Node*)malloc(sizeof(Node));
		for (i = 0, j = len; i < j; i++, j--)
		{
			p = p->next;
			k = 0;
			q = head;
			while (k < j)
			{
				q = q->next;
				k++;
			}

			temp->data = p->data;
			p->data = q->data;
			q->data = temp->data;
		}
	}
	



	//int len = 0;
	//Node *p = head;
	//if (head->next == NULL)
	//{
	//	len = 0;
	//	return 0;
	//}
	//while (p->next != NULL)
	//{
	//	p = p->next;
	//	len++;
	//}	
	//Node *p;// [len];
	//Node *q;




}


/*
Args:
* head: pointer of the head node.
Returns:
* None
Description:
* Print the linked list.
*/
void PrintList(Node* head)
{
    Node *p = head->next;
    if (p == NULL) {
        printf("Empty List");
    }
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
