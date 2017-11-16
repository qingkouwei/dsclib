#include "Common.h"

#include <stdio.h>



#define USEC_PER_SEC  1000000L

void random_initialize(int a[], int size){
	int i;
	srand((unsigned int)time(NULL));
    for (i = 0;i < size; i++ ){
    	 a[i]=rand()%100;
    }
}
void printfArray(int a[], int start, int size){
	int i;
	for(i = start; i < size; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
uint64_t tsDiff(struct timeval *tv1, struct timeval *tv2)
{
	uint64_t t1 = ((uint64_t)tv1->tv_sec) * USEC_PER_SEC + ((uint64_t)tv1->tv_usec);
	uint64_t t2 = ((uint64_t)tv2->tv_sec) * USEC_PER_SEC + ((uint64_t)tv2->tv_usec);

	if (t1 > t2) {
		return (t1 - t2);
	}
	else {
		return (t2 - t1);
	}
}