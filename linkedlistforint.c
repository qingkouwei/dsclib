#include "linkedlist.h"
#include <stdio.h>
Status MakeNode(Link *p, ElemType e){
	*p = (Link)malloc(sizeof(struct LLNode));
	if(!*p){
		return OVERFLOW;
	}
	(*p)->data = e;
	(*p)->next = NULL;
	return OK;
}
void FreeNode(Link *p){
	free(*p);
	*p = NULL;
}


Status InitList(LinkedList *L){
	Link head;
	head = (Link)malloc(sizeof(struct LLNode));
	if(head){
		head->next = NULL;
		L->len = 0;
		L->head=L->tail=head;
		return OK;
	}else{
		return OVERFLOW;
	}
}
Status DestroyList(LinkedList *L){
	ClearList(L);
	FreeNode(&(*L).head);
	(*L).tail = NULL;
	(*L).len = 0;
	return OK;
}
Status ClearList(LinkedList *L){
	Link p, q;
	if((*L).head != (*L).tail){
		p = (*L).head->next;
		(*L).head->next = NULL;
		while(p != (*L).tail){
			q = p->next;
			FreeNode(&p);
			p = q;
		}
		(*L).len = 0;
		(*L).tail = (*L).head;
	}
	return OK;
}
Status InsFirst(LinkedList *L, Link s){
	Link p = (*L).head->next;
	(*L).head->next = s;
	int i =1;
	while(s->next){
		s = s->next;
		i++;
	}
	(*L).len+=i;
	s->next = p;
	if((*L).head == (*L).tail){
		(*L).tail = s;
	}
	return OK;
}
Status DelFirst(LinkedList *L, Link *q){
	Link h = (*L).head;
	*q = h->next;
	if(*q){
		h->next = (*q)->next;
		if(!h->next){
			(*L).tail = h;
		}
		(*L).len--;
		return OK;
	}else{
		return ERROR;
	}
}
Status Append(LinkedList *L, Link s){
	(*L).tail->next = s;
	int i = 1;
	while(s->next){
		s = s->next;
		i++;
	}
	(*L).tail = s;
	(*L).len+=i;
	return OK;
}
Status Remove(LinkedList *L, Link *q){
	*q = (*L).tail;
	if(!*q){
		return ERROR;
	}else{
		Link p = (*L).head;
		while(p->next != *q){
			p = p->next;
		}
		p->next = NULL;
		(*L).tail = p;
		(*L).len--;
		return OK;
	}
}
Status InsBefore(LinkedList *L, Link *p, Link s){
	Link q = PriorPos(*L, *p);
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
	(*L).len +=i;
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
Status InsAfter(LinkedList *L, Link *p, Link s){
	Link q = *p;
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
	q->next = (*p)->next;
	(*L).len += i;
	if(*p == (*L).tail){
		(*L).tail = q;
	}
	return OK;
}
Status SetCurElem(Link p, ElemType e){
	p->data = e;
	return OK;
}
ElemType GetCurElem(Link p){
	return p->data;
}
Status ListEmpty(LinkedList L){
	if(L.len == 0){
		return TRUE;
	}else{
		return FALSE;
	}
}
int ListLength(LinkedList L){
	return L.len;

}
Position GetHead(LinkedList L){
	return L.head;
}
Position GetLast(LinkedList L){
	return L.tail;
}
Position PriorPos(LinkedList L, Link p){
	Link h = L.head->next;
	while(h && h->next != p){
		h = h->next;
	}
	return h;
}
Position NextPos(Link p){
	return p->next;
}
Status LocatePos(LinkedList L, int i, Link *p){
	if(i < 0 && i > L.len){//i==0 is Head Node
		*p = NULL;
		return ERROR;
	}
	int j = 1;
	*p = L.head;
	while(j <=i){
		*p = (*p)->next;
		j++;
	}
	return OK;
}
Position LocateElem(LinkedList L, ElemType e, Status(*compare)(ElemType, ElemType)){
	Link p = L.head->next;
	while(p){
		if(compare(p->data, e)){
			return p;
		}
		p = (p)->next;
	}
	return p;
}
Status ListTraverse(LinkedList L, void(*visit)(ElemType)){
	Link p = L.head->next;
	while(p){
		visit(p->data);
		p = p->next;
	}
	return OK;
}
