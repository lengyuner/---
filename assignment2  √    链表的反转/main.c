#include <stdio.h>
#include <assert.h>
#include "LinkList.h"
#include <crtdbg.h>//add this header file to detect memory leaks
int main(int argc, char* argv[])
{
	Node *head, *p;
	int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int i;
	// If your code is compiled successfully, you will get 60.
	printf("60\n");
	// If you create an empty linked list and reverse it successfully, you will get 70.
	head = CreateEmptyList();
	reverseList(head);
	assert(head->next == NULL);
	DestroyList(head);
	printf("70\n");
	// If you create a linked list contained 10 elements and reverse it successfully, you will get 90.
	head = CreateList(array, 10);
	reverseList(head);
	p = head->next;
	for(i=0;i<10;++i)
	{
		assert(p->data == array[9-i]);
		p=p->next;
	}
	printf("90\n");
	// If you destroy all linked list successfully , you will get 100.
	DestroyList(head);
	if (!_CrtDumpMemoryLeaks())
	{
		printf("100\n");
	}

	return 0;
}
