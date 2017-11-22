#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__
#include "Common.h"
#include "linkedlist.h"


typedef struct {
	float coef;
	int expn;
}term;


typedef LinkList polynomial;

void CreatePolyn(polynomial &P, int m);
void DestroyPolyn(polynomial &P);
void PrintPolyn(polynomial P);
int PolynLength(polynomial P);
void AddPolyn(polynomial &Pa, polynomial &pb);
void SubtractPolyn(polynomial &Pa, polynomial &Pb);
void MultiplyPolyn(polynomial &Pa, polynomial &Pb);

#endif