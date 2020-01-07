#include "BST.h"

/*
Args:
* root: The root pointer of the BST
   arr: The pointer to a integer array
   len: The length of the data, which needs to be stored in BST

Description:
* Create an BST with arr whose length is len
*/
void CreateBST(BST_P *root, int *arr, int len)
{
	for (int i = 0; i < len; i++)
		InsertBSTNode(root, arr[i]);
}



/*
Args:
* root: The root pointer of the BST

Description:
* Destroy root BST, free all the memory of root BST
*/
void DestoryBST(BST_P *root)
{
	if ((*root)->lchild != NULL) DestoryBST(&((*root)->lchild));
	if ((*root)->rchild != NULL) DestoryBST(&((*root)->rchild));
	(*root)->lchild = (*root)->rchild = NULL;
	free(*root); *root = NULL;
}

static BST_P BuyNode(int data)   {

	BST_P pTmp = (BST_P)malloc(sizeof(BST_T));
	if (NULL == pTmp)
	{
		exit(0);
	}
	pTmp->data = data;
	pTmp->lchild = NULL;
	pTmp->rchild = NULL;
	return pTmp;
}


/*
Args:
* root: The root pointer of the BST
  data: The data you want to insert into BST

Description:
* Insert data into the root BST,return true.
* ATTENTION: If data already exist in BST, DO NOTIHNG and return false.
*/
bool InsertBSTNode(BST_P *root, DataType data)
{
	BST_T *p;

	if (*root == NULL) {
		*root = BuyNode(data);
		return 1;
	}
	p = *root;
	while (p != NULL) {
		if (data == p->data) return 0;
		if (data < p->data) {
			if (p->lchild != NULL) {
				p = p->lchild;
			}
			else {
				p->lchild = BuyNode(data);
				return 1;
			}
		}
		if (data > p->data) {
			if (p->rchild != NULL) {
				p = p->rchild;
			}
			else {
				p->rchild = BuyNode(data);
				return 1;
			}
		}
	}
	return 0;

}


/*
Args:
* root: The root pointer of the BST
  data: The data you want to delete from BST

Description:
* Delete data from the root BST, and free the memory
* ATTENTION: If data doesn't exist in BST, DO NOTIHNG and return false.
*/
bool DeleteBSTNode(BST_P *root, DataType data)
{
	BST_P p, q, L, R;
	L = R = NULL;
	p = *root;
	while ((p != NULL) && (p->data != data)) {
		if (data < p->data) {
			L = p;
			p = p->lchild;
		}
		else {
			R = p;
			p = p->rchild;
		}
	}
	if (p == NULL) return 0;
	if (p->lchild == NULL && p->rchild == NULL) {
		if (R != NULL && R->rchild->data == p->data)
			R->rchild = NULL;
		else
			L->lchild = NULL;
		free(p);
	}
	else if (p->lchild != NULL && p->rchild == NULL) {
		if (R != NULL && R->rchild->data == p->data)
			R->rchild = p->lchild;
		else
			L->lchild = p->lchild;
		p->lchild = NULL; free(p);
	}
	else if (p->lchild == NULL && p->rchild != NULL) {
		if (R != NULL && R->rchild->data == p->data)
			R->rchild = p->rchild;
		else
			L->lchild = p->rchild;
		p->rchild = NULL; free(p);
	}
	else {
		q = p->lchild;
		while (q->rchild != NULL) {
			R = q; q = q->rchild;
		}
		p->data = q->data;
		if (q->lchild != NULL) {
			R->rchild = q->lchild;
			q->lchild = NULL;
		}
		else R->rchild = NULL;
		free(q);
	}
	return 1;
}

/*
Args:
* root: The root pointer of the BST
  data: The data you want to search

Description:
* Search data within the root BST, and return its BST pointer
* ATTENTION: If data doesn't exist in BST, return NULL.
*/
BST_P SearchBST(BST_P *root, DataType data)
{
	BST_T *p;
	p = *root;
	while ((p != NULL) && (p->data != data)) {
		if (data < p->data) {
			p = p->lchild;
		}
		else {
			p = p->rchild;
		}
	}
	return p;
}



/*
Args:
* root: The root pointer of the BST

Description:
* visualize the MidOrderTraverse of root BST
*/
void MidOrderTraverse(BST_P root)
{
	if (root!=NULL)
	{
		MidOrderTraverse(root->lchild);
		printf("%d, ", root->data);
		MidOrderTraverse(root->rchild); 
	}
}

