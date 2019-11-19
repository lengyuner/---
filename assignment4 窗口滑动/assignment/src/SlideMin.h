#pragma once
#ifndef _SLIDEMIN_H_
#define _SLIDEMIN_H_
#include "Queue.h"

#define N 9
#define K 3

#define LONG_N 1000000
#define LONG_K_1 10
#define LONG_K_2 100000

/*
Args:
* q:In a particular slide,q is a pointer to a Monotonically increasing Double-ended Queue of index within the current window.What's more, it's front value should store the minimum value's idx within current window.
	eg. array : [3, 2, 5, 1]
		first slide :
		window size : 3
		window's value: [3, 2, 5]
		Monotonically increasing DeQueue *q:[1, 2]	cause value 2's index is 1, and value 5's index is 2

		second slide:
		window size : 3
		window's value:	[2, 5, 1]
		Monotonically increasing DeQueue *q:[3]	cause value 1's index is 3

* array: pointer to the given whole array,whose length is N
	eg. array : [3, 2, 5, 1]

* res:pointer to a Double-ended Queue,which stores the result of sliding window's minmum value
	eg. array : [3, 2, 5, 1]
		window size : 3
		first slide window's minimum index; 1, minimum value: 2 
		second slide window's minimum index; 4, minimum value: 1
		res: [2, 1]
Description:func
*/
void SlideMin(PQueue q, DataType* array, PQueue res, int n, int k);


#endif