#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__
#include "Common.h"
#include "linkedlist.h"


typedef struct {
	float coef;
	int expn;
}term;


typedef LinkedList polynomial;

void assignTerm(void *e1, void *e2);
Status OrderInsertMerge(polynomial *P, term e, int(*compare)(void*, void*));
void Opposite(polynomial Pa);

void CreatePolyn(polynomial *P, int m);
void DestroyPolyn(polynomial *P);
void PrintPolyn(polynomial P);
int PolynLength(polynomial P);
void AddPolyn(polynomial *Pa, polynomial *pb);
void AddPolyn2(polynomial *Pa, polynomial *pb);
void SubtractPolyn(polynomial *Pa, polynomial *Pb);
void MultiplyPolyn(polynomial *Pa, polynomial *Pb);

#endif