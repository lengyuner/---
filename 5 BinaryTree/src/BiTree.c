#include "BiTree.h"

/*
Args:
* s:the string of preorder traversal sequence.

for example:
if you want to obtain an element of s,you can write the code:
	DataType data = *((*s));
if you want to obtain the second element of s,you can write the code:
	(*s)++;
	DataType data = *((*s));


Return:
* Pointer of the bitree node.
Description:
* Create a bitree from preorder traversal sequence.
*/
BinaryTree CreateBinaryTreeFromPreOrderSequence(DataType **s)
{
	//int len = sizeof(s) / sizeof(*(*(s)));
	//DataType temp;
	//temp = *((*s));
	////int a[10];	
	//BinaryTree tree;
	//tree = (BinaryTree)malloc(sizeof(BinaryNode));
	//if (tree == NULL)
	//{
	//	printf("error.\n");
	//	return 0;//exit();
	//}
	//tree->data = temp;
	//(*s)++;
	//if (*((*s)) == '*')
	//else
	//	tree->right=CreateBinaryTreeFromPreOrderSequence(**s);


	
	/*
	BtNode *p = NULL;
	if (str != NULL && *str != NULL && **str != '#')
	{
		p = Buynode();
		p->data = **str;
		p->leftchild = Createtree1(++*str);
		p->rightchild = Createtree1(++*str);
	}
	return p;
	*/

	BinaryNode *p = NULL;
	if (s != NULL && *s != NULL && **s != '*')
	{
		p = (BinaryTree)malloc(sizeof(BinaryNode));
		p->data = **s;
		p->left = CreateBinaryTreeFromPreOrderSequence(++*s);
		p->right = CreateBinaryTreeFromPreOrderSequence(++*s);
	}
}

/*
Args:
* t:the pointer of the bitree.
* s:the string of preorder traversal sequence you returned.
Return:
* None.
Description:
* return preorder traversal sequence of the bitree.
*/
void PreOrderTraversal(BinaryTree t, DataType **s)
{
	if (t == NULL)
	{
		return 0;
	}
	**s = t->data;
	(*s)++;
	PreOrderTraversal(t->left, **s);
	PreOrderTraversal(t->right, **s);

}

/*
Args:
* t:the pointer of the bitree.
* s:the string of ineorder traversal sequence you returned.
Return:
* None.
Description:
* return inorder traversal sequence of the bitree.
*/
void InOrderTraversal(BinaryTree t, DataType **s)
{
	if (t == NULL)
	{
		return 0;
	}
	PreOrderTraversal(t->left, **s);
	**s = t->data;
	(*s)++;
	PreOrderTraversal(t->right, **s);
}

/*
Args:
* t:the pointer of the bitree.
* s:the string of postorder traversal sequence you returned.
Return:
* None.
Description:
* return postorder traversal sequence of the bitree.
*/
void PostOrderTraversal(BinaryTree t, DataType **s)
{
	if (t == NULL)
	{
		return 0;
	}
	PreOrderTraversal(t->left, **s);
	PreOrderTraversal(t->right, **s);
	**s = t->data;
	(*s)++;
}



/*
Args:
* head: pointer of the bitree.
Returns:
* None
Description:
* Destroy the bitree.
* Release all allocated memory.
*/
BinaryTree DestroyTree(BinaryTree T)
{
	T = NULL;
	//if (T)                                          //Èç¹ûT´æÔÚ
	//{
		//DestroyTree(T->left);
		//DestroyTree(T->right);
		//free(T);
	//}
}