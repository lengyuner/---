#include "SlideMin.h"

/*
Args:
* q:In a particular slide,
q is a pointer to a Monotonically increasing Double-ended Queue of index within the current window.
What's more, it's front value should store the minimum value's idx within current window.
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
void SlideMin(PQueue q, DataType* array, PQueue res, int n, int k)
{
	//DataType min;
	DataType temp=0;// , temp1;
	//min = array[0];
	int k1, k2;
	InsertRight(q, array[0]);
	//构造 前k个数 的 单增序列
	for (k1 = 1; k1 < k; k1++)
	{
		//temp = array[k1];
		for (k2 = q->rear; array[k1] < q->base[k2]; k2--)
		{
			if (array[k1] < q->base[k2])
			{
				DeleteRight(q, temp);
			}
			if (k2 == q->front)
			{
				break;
			}
		}
		if (k2 < q->rear)
		{
			InsertRight(q, array[k1]);
		}
	}
	InsertRight(res, q->base[q->front]);
	
	//开始扫描窗口
	//暂时未解决 出栈问题，已经解决
	//通过一个判断语句，判断 单调队列首个值 是不是 窗口首个值 ，解决了上述问题
	for ( k1 = k; k1 < n; k1++)
	{
		if (array[k1 - k] == q->base[q->front])		
		{
			DeleteLeft(res, temp);
		}
		for (k2 = q->rear; array[k1] < q->base[k2]; k2--)
		{
			if (array[k1] < q->base[k2])
			{
				DeleteRight(q, temp);
			}
			if (k2 == q->front)
			{
				break;
			}
		}
		if (k2 < q->rear)
		{
			InsertRight(q, array[k1]);
		}
		InsertRight(res, q->base[q->front]);
	}
}




//DeleteRight(q, temp);
//InsertRight(q, min);
