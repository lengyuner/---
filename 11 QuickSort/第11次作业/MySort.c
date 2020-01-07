#include "MySort.h"
void Myqsort(int *array,int size)
{
	//øÏÀŸ≈≈–Ú
	int low;
	int high;
	low = 0;
	high = size-1;
	// sizeof(array) / sizeof(array[0]);
	Qsort(array, low, high);
}

void Qsort(int *array, int low, int high)
{
	/*for (int i = 0; i < LONG_N; i++)
		printf("%d\t", array[i]);
	printf("\n");*/
	if (low < high)
	{
		int pivotloc;
		pivotloc = Partition(array, low, high);
		//printf("\n%d\n", pivotloc);
		Qsort(array, low, pivotloc - 1);
		Qsort(array, pivotloc + 1, high);
	}
	
}


int Partition(int *array, int low, int high)
{
	int temp;
	temp = array[low];	//int pivot = array[low]
	while (low < high)
	{
		while (low<high && array[high]>=temp)
		{
			--high;
		}
		array[low] = array[high];
		while (low<high && array[low]<=temp)
		{
			++low;
		}
		array[high] = array[low];
	}
	array[low] = temp;// array[high];
	return low;
}




