#include "Queue.h"
#include "SlideMin.h"
#include<assert.h>
#include<stdio.h>
#include <crtdbg.h>//add this header file to detect memory leaks
#include <stdlib.h>
#include <time.h>

int main(int argc,char*argv[])
{
	int temp = 0;

	PQueue Q;
	PQueue R;
    int i;
	int val;
	int *array_long;
	clock_t start, finish;
	int duration;
	int array_right[5] = { 5, 6, 7, 8, 9 };
	int array_left[5] = { 4, 3, 2, 1, 0 };
	int array_test[N] = { 3, 2, 5, 1, 2, 6, 8, 3, 1 };
	int array_result[N - K + 1] = { 2, 1, 1, 1, 2, 3, 1 };
	
	printf("60\n");//If you compile successfully, you will get 60!
	Q=CreatQueue(MAXSIZE);
	assert(Q->base != NULL&&Q->front==0&&Q->rear==0&& Q->maxsize == MAXSIZE);
	printf("70\n");//If you initialize the queue sucessfully, you will get 70!
	
	for (i = 0; i < 5; ++i)
	{
		InsertRight(Q, array_right[i]);
	}
	for (i = 0; i < 5; ++i)
	{
		InsertLeft(Q, array_left[i]);
	}
	Length(Q);
	printf("\n%d\n", Length(Q));
    assert(Length(Q) == 10);
    assert(Full(Q)==true);
	printf("\t%d=?=%d\t", Q->front, 6);//  7 6

	printf("\t%d=?=%d\t", Q->rear, 5);

	printf("\n\n");
	//assert(Q->front == 6 && Q->rear == 5);
	assert(InsertLeft(Q, 10) == false && InsertRight(Q, -1) == false);
	//The Double-ended Queue is full.If you insert a number,it will return false;
	for (i = 0; i < 10; ++i)
	{
		printf("\t%d=?=%d\t", Q->base[(Q->front + i) % Q->maxsize], i);
		//assert(Q->base[(Q->front + i) % Q->maxsize] == i);
	}

	for (i = 0; i < 5; ++i)
	{
		if (DeleteRight(Q, &val))
		{
			printf("\t%d=?=%d\t", val, array_right[4 - i]);
			//assert(val == array_right[4 - i]);
		}
	}
	
	for (i = 0; i < 5; ++i)
	{
		if (DeleteLeft(Q, &val))
		{
			printf("\t%d=?=%d\t", val, array_left[4 - i]);
			//assert(val == array_left[4 - i]);
		}
	}

	assert(Length(Q) == 0);
	assert(Empty(Q) == true);
	assert(DeleteLeft(Q, &val) == false && DeleteRight(Q, &val) == false);//The Double-ended Queue is empty.If you delete a number,it will return false;
	printf("80\n");//If you  InsertLeft, InsertRight, DeleteLeft and DeleteRight the Double-ended Queue sucessfully, you will get 75!
	DestroyQueue(&Q);
	assert(Q == NULL);
	if (!_CrtDumpMemoryLeaks())
	{
		printf("85\n");
	}
	
	Q = CreatQueue(K + 1);
	R = CreatQueue(N - K + 2);
	SlideMin(Q, array_test, R, N, K);
	assert(Length(R) == N - K + 1);
	assert(Full(R) == true);
	for (i = 0; i < N - K; ++i)
	{
		assert(R->base[(R->front + i) % R->maxsize] == array_result[i]);//if you store the correct answer in R,you will pass this!
	}
	printf("90\n");
	DestroyQueue(&Q);
	assert(Q == NULL);
	DestroyQueue(&R);
	assert(R == NULL);
	if (!_CrtDumpMemoryLeaks())
	{
		printf("95\n");
	}

	printf("first and second time's value should similiar!\n");
	array_long = (int*)malloc(LONG_N * sizeof(int));
	srand((unsigned int)time(NULL));
	for (i = 0; i < LONG_N; ++i)
	{
		array_long[i] = (int)(rand());
	}
	Q = CreatQueue(LONG_K_1 + 1);
	R = CreatQueue(LONG_N - LONG_K_1 + 2);
	start = clock();
	SlideMin(Q, array_long, R, LONG_N, LONG_K_1);
	finish = clock();
	duration = (finish - start);
	printf("first: %d ms\n", duration);
	DestroyQueue(&Q);
	assert(Q == NULL);
	DestroyQueue(&R);
	assert(R == NULL);

	Q = CreatQueue(LONG_K_2 + 1);
	R = CreatQueue(LONG_N - LONG_K_2 + 2);
	start = clock();
	SlideMin(Q, array_long, R, LONG_N, LONG_K_2);
	finish = clock();
	duration = (finish - start);
	printf("second: %d ms\n", duration);
	DestroyQueue(&Q);
	assert(Q == NULL);
	DestroyQueue(&R);
	assert(R == NULL);
	free(array_long);

	if (!_CrtDumpMemoryLeaks())
	{
		printf("100!\n");
	}
	return 0;
}
