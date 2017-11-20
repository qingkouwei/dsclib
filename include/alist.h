/*
 *Module Name:
 *Module Date:
 *Module Auth:
 *Description: Array list
 *Others:
 *evision History:
 *DateRel VerNotes
 *XX/XX/XXXXX.X
*/
#ifndef __ALIST_H__
#define __ALIST_H__

#include "Common.h"
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef int ElemType;

typedef struct{
    ElemType *elems;
    int length;
    int listSize;
}SqList;

Status InitList_Sq(SqList *L);
Status DestroyList_Sq(SqList *L);
Status ClearList_Sq(SqList *L);
Status List_SqEmpty(SqList L);
int List_SqLength(SqList L);
Status GetElem_Sq(SqList L, int i , ElemType *e);
int LocateElem_Sq(SqList *L, ElemType e, Status(*compare)(ElemType, ElemType));
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType *pre_e);
Status NextElem_Sq(SqList L, ElemType cur_e, ElemType *next_e);
Status List_SqInsert(SqList *L, int i, ElemType e);
Status List_SqDelete(SqList *L, int i, ElemType *e);
Status List_SqTraverse(SqList L, void(*vi)(ElemType));


#endif