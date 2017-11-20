#include "alist.h"

Status InitList_Sq(SqList *L){
    L->elems=(ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(!L->elems)
        exit(OVERFLOW);
    L->length = 0;
    L->listSize = LIST_INIT_SIZE;
    return OK;
}
Status DestroyList_Sq(SqList *L){
    free(L->elems);
    L->elems=NULL;
    L->length=0;
    L->listSize=0;
    return OK;
}
Status ClearList_Sq(SqList *L){
    L->length = 0;
    return OK;
}
Status List_SqEmpty(SqList L){
    if(L.length == 0){
        return TRUE;
    }
    return FALSE;
}
int List_SqLength(SqList L){

    return L.length;
}
Status GetElem_Sq(SqList L, int i , ElemType *e){
    if(i<1 || i>L.length){
        return ERROR;
    }
    *e=*(L.elems+i-1);
    return OK;
}
int LocateElem_Sq(SqList *L, ElemType e, Status(*compare)(ElemType, ElemType)){
    ElemType *p;
    int i = 1;
    p=L->elems;
    while(i<=L->length && !compare(*p++, e)){
        ++i;
    }
    if(i<=L->length){
        return i;
    }
    return 0;
}
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType *pre_e){
    int i=2;
    ElemType *p=L.elems + 1;
    while(i<=L.length&&*p!=cur_e){
        p++;
        i++;
    }
    if(i>L.length){
        return INFEASIBLE;
    }
    *pre_e = *--p;
    return OK;
}
Status NextElem_Sq(SqList L, ElemType cur_e, ElemType *next_e){
    int i = 1;
    ElemType *p = L.elems;
    while(i<L.length&& *p != cur_e){
        i++;
        p++;
    }
    if(i==L.length){
        return INFEASIBLE;
    }
    *next_e=*++p;
    return OK;
}
Status List_SqInsert(SqList *L, int i, ElemType e){
    ElemType *newbase, *q, *p;
    if(i<1 || i>L->length+1){
        return ERROR;
    }
    if(L->length >= L->listSize){
        newbase=(ElemType *)realloc(L->elems, (LIST_INIT_SIZE + LISTINCREMENT)*sizeof(ElemType));
        if(!newbase){
            return OVERFLOW;
        }
        L->elems = newbase;
        L->listSize += LISTINCREMENT;
    }

    q= L->elems + i -1;
    for(p = L->elems + L->length -1; p>=q; --p){
        *(p+1) = *p;
    }
    *q = e;
    ++L->length;
    return OK;
}
Status List_SqDelete(SqList *L, int i, ElemType *e){
    ElemType *p, *q;
    if(i<1 || i> L->length){
        return ERROR;
    }
    p = L->elems + i -1;
    *e = *p;
    q = L->elems + L->length -1;
    for(++p; p<= q;++p){
        *(p-1) = *p;
    }
    L->length--;
    return OK;
}
Status List_SqTraverse(SqList L, void(*vi)(ElemType)){
    ElemType *p;
    int i;
    p = L.elems;
    for(i = 1; i<= L.length; i++){
        vi(*(p++));
    }
    return OK;
    return OK;
}