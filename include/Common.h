#ifndef __COMMON_H__
#define __COMMON_H__
#include <time.h>
#include <stdlib.h>


#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2


#define TRUE 1
#define FALSE 0


typedef int Status;

void random_initialize(int a[], int size);
void printfArray(int a[], int start, int size);
uint64_t tsDiff(struct timeval *tv1, struct timeval *tv2);
#endif
