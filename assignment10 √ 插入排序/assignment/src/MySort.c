#include "MySort.h"
void Mysort(int *array,int size)//ascending sort
{
	//cout << 0 << endl;
	//printf("0\n");
	//²åÈëÅÅÐò
	/*int i, j;
	for (i = 2; i <= size; i++)
	{
		if (array[i] < array[i - 1])
		{
			array[0] = array[i];
			array[i] = array[i - 1];
			for (j = i - 2; array[0] < array[j]; j--)
			{
				array[j + 1] = array[j];
			}
			array[j + 1] = array[0];
		}
	}
	printf("1\n");
	for (i = 0; i < size; i++)
	{
		printf("%d\t", array[i]);
	}
	*/
	int i, j;
	int temp;
	for (i = 1; i < size; i++)
	{
		temp = array[i];
		/*
		j = i - 1;
		while (j > -1 && temp < array[j])
		{
			array[j + 1] = array[j];
			j--;
		}
		*/
		for (j = i - 1; temp < array[j] ; j--)
		{
			array[j + 1] = array[j];
		}
		array[j + 1] = temp;
	}
	/*for (i = 0; i < size; i++)
	{
		printf("%d\t", array[i]);
	}*/

}

















