#pragma once
#ifndef __MySort_H__
#define __MySort_H__

#include<stdio.h>
#include<stdlib.h>

#define LONG_N 10000

void Myqsort(int *array,int size);
void Qsort(int *array, int low, int high);
int Partition(int *array, int low, int high);

#endif //sort 
