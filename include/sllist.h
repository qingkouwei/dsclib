#ifndef __SLIST_H__
#define __SLIST_H__
#include "Common.h"
typedef int ElemType;

#define MAXSIZE 100
typedef struct{
	ElemType data;
	int cur;
}component, SLinkList[MAXSIZE];

int SLMalloc(SLinkList space);
void SLFree(SLinkList space, int k);
void DestroySLList();
Status InitSLList(SLinkList L);
Status ClearSLList(SLinkList L);
Status SLListEmpty(SLinkList L);
int SLListLength(SLinkList L);
Status GetSLElem(SLinkList L, int i, ElemType *e);
int LocateSLElem(SLinkList L, ElemType e);
Status PriorSLElem(SLinkList L,ElemType cur_e, ElemType *pre_e);
Status NextSLElem(SLinkList L, ElemType cur_e, ElemType *next_e);
Status SLListInsert(SLinkList L, int i, ElemType e);
Status SLListDelete(SLinkList L, int i, ElemType *e);
Status SLListTraverse(SLinkList L, void(*vi)(ElemType, int));

#endif