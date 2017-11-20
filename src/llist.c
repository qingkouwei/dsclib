#include "llist.h"


Status InitLList(LinkList *L){
	*L = (LinkList)malloc(sizeof(LNode));
	if(!(*L)){
		return OVERFLOW;
	}
	(*L)->next = NULL;
	return OK;
}
Status DestroyLList(LinkList *L){
	LinkList q;
	while(*L){
		q = (*L)->next;
		free(*L);
		*L=q;
	}
	return OK;
}
Status ClearLList(LinkList L){
	LinkList p,q;
	p = L->next;
	while(p){
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	return OK;
}
Status LListEmpty(LinkList L){
	if(L->next){
		return FALSE;
	}
	return TRUE;
}
int LListLength(LinkList L){
	int i = 0;
	LinkList p = L->next;
	while(p){
		i++;
		p=p->next;
	}

	return i;
}
Status GetElemL(LinkList L, int i, ElemType *e){
	LinkList p = L->next;
	int j = 1;
	while(p && j < i){
		p = p->next;
		j++;
	}
	if(!p || j>i){
		return ERROR;
	}
	*e = p->data;
	return OK;
}
int LocateElemL(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType)){
	LinkList p = L->next;
	int i = 1;
	while(p){
		if(compare(e, p->data)){
			return i;
		}
		i++;
		p = p->next;
	}
	return 0;
}
Status PriorElemL(LinkList L, ElemType cur_e, ElemType *pre_e){
	LinkList p = L->next;
	*pre_e = p->data;
	p=p->next;
	while(p){
		if(p->data == cur_e){
			return OK;
		}
		*pre_e = p->data;
		p = p->next;
	}
	return INFEASIBLE;
}
Status NextElemL(LinkList L, ElemType cur_e, ElemType *next_e){
	LinkList p ,q;
	p = L->next;
	while(p->next){
		q = p->next;
		if(p->data == cur_e){
			*next_e = q->data;
			return OK;
		}
		p = q;
	}
	return INFEASIBLE;
}
Status LListInsert(LinkList L, int i, ElemType e){
	LinkList p ,s;
	p = L;
	int j = 1;
	while(j<i && p){
		j++;
		p=p->next;
	}
	if(!p&&j>i){
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next=p->next;
	p->next=s;
	return OK;
}
Status LListDelete(LinkList L, int i, ElemType *e){
	int j;
	LinkList p, q;
	p=L;
	j=1;
	while(p->next&& j< i){
		p=p->next;
		j++;
	}
	if(!p->next || j>i){
		return ERROR;
	}
	q = p->next;//location i data,p is location i pre data
	p->next = q->next;
	*e = q->next->data;
	free(q);
	return OK;
}
Status LListTraverse(LinkList L, void(*vi)(ElemType)){
	LinkList p = L->next;
	while(p){
		vi(p->data);
		p = p->next;
	}
	return OK;
}