#include "XSort.h"
#include "Common.h"
#include <stdio.h>
#include <sys/time.h>
static void swap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void BubbleSortFake(SqList *L, bool showDetail){

	int i,j;
	int loopCount, swapCount = 0;
	struct timeval now, end;
	gettimeofday(&now, NULL);
	for(i = 0; i < L->length; i++)
	{
		for(j = i + 1; j < L->length; j++)
		{
			if(L->r[j] < L->r[i])
			{
				swap(L, i, j);
				swapCount++;
			}
			if(showDetail)
			{
				printf("after hand %d round , %d times:\n", i+1, j+1);
				printfArray(L->r, 0, L->length);
			}
			loopCount++;
		}
	}
	gettimeofday(&end, NULL);
	uint64_t cost = tsDiff(&now, &end);
	printf("BubbleSortFake cost loopCount = %d, swapCount = %d, and cost time = %llu us\n", 
		loopCount, swapCount, cost);
	//printfArray(L->r, 0, L->length);
}

void BubbleSortPrimary(SqList *L, bool showDetail){

	int i, j;
	int loopCount, swapCount = 0;
	struct timeval now, end;
	gettimeofday(&now, NULL);
	for(i = 0; i < L->length; i++)
	{
		for(j = L->length - 1; j > i; j--)
		{
			if(L->r[j] < L->r[j - 1])
			{
				swap(L, j, j - 1);
				swapCount++;
			}
			if(showDetail)
			{
				printf("after hand %d round , %d times:\n", i+1, j+1);
				printfArray(L->r, 0, L->length);
			}
			loopCount++;
		}
	}
	gettimeofday(&end, NULL);
	uint64_t cost = tsDiff(&now, &end);
	printf("BubbleSortPrimary cost loopCount = %d, swapCount = %d, and cost time = %llu us\n", 
		loopCount, swapCount, cost);
}

void BubbleSort(SqList *L, bool showDetail){
	int i, j;
	int loopCount, swapCount = 0;
	struct timeval now, end;
	gettimeofday(&now, NULL);
	bool hasSorted = false;
	for(i = 0; i < L->length && !hasSorted; i++)
	{
		hasSorted = true;
		for(j = L->length - 1; j > i; j--)
		{

			if(L->r[j] < L->r[j - 1])
			{
				swap(L, j, j - 1);
				hasSorted = false;
				swapCount++;
			}
			if(showDetail)
			{
				printf("after hand %d round , %d times:\n", i+1, j+1);
				printfArray(L->r, 0, L->length);
			}
			loopCount++;
		}
	}
	gettimeofday(&end, NULL);
	uint64_t cost = tsDiff(&now, &end);
	printf("BubbleSort cost loopCount = %d, swapCount = %d, and cost time = %llu us\n", 
		loopCount, swapCount, cost);
}

void SelectSort(SqList *L, bool showDetail){

}

void InsertSort(SqList *L, bool showDetail){

}

void ShellSort(SqList *L, bool showDetail){

}