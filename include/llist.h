/**
*linklist
**/
#ifndef __LLIST_H__
#define __LLIST_H__

#include "Common.h"
typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
} LNode;

typedef struct LNode *LinkList;


Status InitLList(LinkList *L);
Status DestroyLList(LinkList *L);
Status ClearLList(LinkList L);
Status LListEmpty(LinkList L);
int LListLength(LinkList L);
Status GetElemL(LinkList L, int i, ElemType *e);
int LocateElemL(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType));
Status PriorElemL(LinkList L, ElemType cur_e, ElemType *pre_e);
Status NextElemL(LinkList L, ElemType cur_e, ElemType *next_e);
Status LListInsert(LinkList L, int i, ElemType e);
Status LListDelete(LinkList L, int i, ElemType *e);
Status LListTraverse(LinkList L, void(*vi)(ElemType));
#endif