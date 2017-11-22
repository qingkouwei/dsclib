#include "linkedlist.h"
#include <stdio.h>

typedef struct node{
	void* data;
	struct node *next;
}Node;

struct list{
	Iterator head, tail;
	int data_size;//elem size 
	int len;
};

Status MakeNode(Iterator *p, void *data, int data_size,void (*assign)(void*, void*)){
	*p = (Iterator)malloc(sizeof(struct node));
	if(!*p){
		return OVERFLOW;
	}
	(*p)->data = malloc(data_size);
	assign((*p)->data,data);
	(*p)->next = NULL;
	return OK;
}
void FreeNode(Iterator *p){
	free((*p)->data);
	free(*p);
	*p = NULL;
}


Status InitList(LinkedList *L, int data_size){

	LinkedList list = (LinkedList)malloc(sizeof(struct list));
	if(!list){
		return OVERFLOW;
	}
	//printf("list:%p\n", list);
	*L = list;
	//printf("L: %p\n", L);
	Iterator head;
	head = (Iterator)malloc(sizeof(struct node));
	if(head){
		head->next = NULL;
		head->data = NULL;
		(*L)->len = 0;
		(*L)->data_size=data_size;
		(*L)->head=(*L)->tail=head;
		return OK;
	}else{
		return OVERFLOW;
	}
}
Status DestroyList(LinkedList L){
	ClearList(L);
	FreeNode(&L->head);
	L->tail = NULL;
	L->len = 0;
	return OK;
}
Status ClearList(LinkedList L){
	Iterator p, q;
	if(L->head != L->tail){
		p = L->head->next;
		L->head->next = NULL;
		while(p != L->tail){
			q = p->next;
			FreeNode(&p);
			p = q;
		}
		L->len = 0;
		L->tail = L->head;
	}
	return OK;
}
Status InsFirstH(LinkedList L, Iterator h, Iterator s){
	Iterator p = h->next;
	h->next = s;
	int i =1;
	while(s->next){
		s = s->next;
		i++;
	}
	L->len+=i;
	s->next = p;
	if(h == L->tail){
		L->tail = s;
	}
	return OK;
}
Status DelFirstH(LinkedList L, Iterator h, Iterator *q){
	*q = h->next;
	if(*q){
		h->next = (*q)->next;
		if(!h->next){
			L->tail = h;
		}
		L->len--;
		return OK;
	}else{
		return ERROR;
	}
}
Status InsFirst(LinkedList L,Iterator s){
	return InsFirstH(L, L->head, s);
}
Status DelFirst(LinkedList L,Iterator *q){
	return DelFirstH(L, L->head, q);
}
Status Append(LinkedList L, Iterator s){
	L->tail->next = s;
	int i = 1;
	while(s->next){
		s = s->next;
		i++;
	}
	L->tail = s;
	L->len+=i;
	return OK;
}
Status Remove(LinkedList L, Iterator *q){
	*q = L->tail;
	if(!*q){
		return ERROR;
	}else{
		Iterator p = L->head;
		while(p->next != *q){
			p = p->next;
		}
		p->next = NULL;
		L->tail = p;
		L->len--;
		return OK;
	}
}
Status InsBefore(LinkedList L, Iterator *p, Iterator s){
	Iterator q = PriorPos(L, *p);
	if(!q){
		return ERROR;
	}
	int i = 0;
	while(s){
		q->next = s;
		q= q->next;
		s = s->next;
		i++;
	}
	q->next = *p;
	L->len +=i;
	return OK;
	/*if(*p == NULL){
		return ERROR;
	}
	Link h = (*L).head;
	while(h && h->next != *p){
		h = h->next;
	}
	if(h->next != *p){
		return INFEASIBLE;
	}
	int i = 1;
	while(s){
		h->next = s;
		h= h->next;
		i++;
		s = s->next;
	}
	h->next = *p;
	(*L).len +=i;
	if(!(*L).tail){
		(*L).tail = h;
	}
	return OK;*/
}
Status InsAfter(LinkedList L, Iterator *p, Iterator s){
	Iterator q = *p;
	Iterator next = (*p)->next;
	if(!q){
		return ERROR;
	}
	int i = 0;
	while(s){
		q->next = s;
		q = q->next;
		s = s->next;
		i++;
	}
	q->next = next;
	L->len += i;
	if(*p == L->tail){
		L->tail = q;
	}
	return OK;
}
Status SetCurElem(Iterator p, void *e, void (*assign)(void*, void*)){
	assign(p->data, e);
	return OK;
}
void* GetCurElem(Iterator p){
	return p->data;
}
Status ListEmpty(LinkedList L){
	if(L->len == 0){
		return TRUE;
	}else{
		return FALSE;
	}
}
int ListLength(LinkedList L){
	return L->len;

}
void setListLength(LinkedList L, int len){
	L->len = len;
}

Iterator GetHead(LinkedList L){
	return L->head;
}
Status SetHead(LinkedList L, Iterator p){
	L->head = p;
	return OK;
}
Iterator GetLast(LinkedList L){
	return L->tail;
}
Status SetTail(LinkedList L, Iterator p){
	L->tail = p;
	return OK;
}
Iterator PriorPos(LinkedList L, Iterator p){
	Iterator h = L->head->next;
	while(h && h->next != p){
		h = h->next;
	}
	return h;
}
Iterator NextPos(Iterator p){
	return p->next;
}
Status LocatePos(LinkedList L, int i, Iterator *p){
	if(i < 0 && i > L->len){//i==0 is Head Node
		*p = NULL;
		return ERROR;
	}
	int j = 1;
	*p = L->head;
	while(j <=i){
		*p = (*p)->next;
		j++;
	}
	return OK;
}
Iterator LocateElem(LinkedList L, void *e, Status(*compare)(void*, void*)){
	Iterator p = L->head->next;
	while(p){
		if(compare(p->data, e)){
			return p;
		}
		p = (p)->next;
	}
	return p;
}
Status ListTraverse(LinkedList L, void(*visit)(void *)){
	Iterator p = L->head->next;
	while(p){
		visit(p->data);
		p = p->next;
	}
	return OK;
}
Status OrderInsert(LinkedList L, Iterator s, int (*compare)(void *, void *)){

	Iterator pp, p = L->head;
	do{
		pp = p;
		p = p->next;
	}while(p&&(compare(p->data, s->data) < 0));
	pp->next = s;
	s->next = p;
	L->len++;
	if(s->next){
		L->tail=s;
	}
	if(!p || (compare(p->data, s->data) > 0)){
		return FALSE;
	}else{
		return TRUE;
	}
}

Status LocateElemP(LinkedList L, void *e, Iterator *q,int (*compare)(void*, void*)){
	Iterator p = L->head;
	Iterator pp=L->head;
	do{
		pp = p;
		p = p->next;
	}while(p&&(compare(p->data,e)<0));

	if(!p || compare(p->data, e) > 0){
		*q = pp;
		return FALSE;
	}else{
		*q = p;
		return TRUE;
	}
}