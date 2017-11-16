/**********************************************************
 * Sort
 *
 * ******************************************************/
#ifndef __XSort_H__
#define __XSort_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>

#define MAXSIZE 100000

typedef struct
{
	int r[MAXSIZE -1];
	int length;
}SqList;

void BubbleSortFake(SqList *L, bool showDetail);

void BubbleSortPrimary(SqList *L, bool showDetail);

void BubbleSort(SqList *L, bool showDetail);

void SelectSort(SqList *L, bool showDetail);

void InsertSort(SqList *L, bool showDetail);

void ShellSort(SqList *L, bool showDetail);

#ifdef __cplusplus
}
#endif

#endif