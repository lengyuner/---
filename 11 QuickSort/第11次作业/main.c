#include<assert.h>
#include<stdio.h>
//#include <crtdbg.h>//add this header file to detect memory leaks
#include <stdlib.h>
#include<string.h>
#include <time.h>
#include"Mysort.h"

int cmp(const void*a, const void*b)//ascending order
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int i;
	int array_long[LONG_N];
	int num = 10;
	clock_t start,stop;
	while (num--)
	{
		for (i = 0; i < LONG_N; ++i)
		{
			array_long[i] = (int)(rand());
		}
		int array_long_target[LONG_N];
		int array_long_test[LONG_N];
		memcpy(array_long_target, array_long, LONG_N * sizeof(int));
		memcpy(array_long_test, array_long, LONG_N * sizeof(int));
		start =clock();
		qsort(array_long_target, LONG_N, sizeof(int), cmp);
		stop=clock();
		printf("The time of standard qsort:%f\n",(double)(stop-start)/CLK_TCK);
		start=clock();
		Myqsort(array_long_test, LONG_N);
		stop=clock();
        printf("The time of my qsort:%f\n",(double)(stop-start)/CLK_TCK);
		for (i = 0; i < LONG_N; ++i)
		{
			/*
			printf("%d=?=%d\t", array_long_test[i], array_long_target[i]);
			if (i % 100 == 0)
			{
				printf("%d=?=%d\t", array_long_test[i], array_long_target[i]);
				if (i % 300 == 0)
				{
					printf("\n");
				}
			}
			*/
			assert(array_long_test[i] == array_long_target[i]);
		}	
	}
	printf("100!\n");
	return 0;
}
