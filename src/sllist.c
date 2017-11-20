#include "sllist.h"

int SLMalloc(SLinkList space){
	int i = space[0].cur;
	if(space[0].cur){
		space[0].cur = space[i].cur;
	}
	return i;
}
void SLFree(SLinkList space, int k){
	space[k].cur = space[0].cur;
	space[0].cur = k;
}
void DestroySLList(){

}
Status InitSLList(SLinkList L){
	int i;
	for(i=0;i<MAXSIZE-1;i++){
		L[i].cur = i+1;
	}
	L[MAXSIZE-1].cur = 0;
	return OK;
}
Status ClearSLList(SLinkList L){
	int i,j,k;
	i = L[MAXSIZE-1].cur;
	L[MAXSIZE-1].cur = 0;

	k = L[0].cur;
	L[0].cur = i;
	while(i){
		j = i;
		i=L[i].cur;
	}

	L[j].cur=k;

	return OK;
}
Status SLListEmpty(SLinkList L){
	if(L[MAXSIZE-1].cur == 0){
		return TRUE;
	}
	return FALSE;
}
int SLListLength(SLinkList L){
	int j=0, i =L[MAXSIZE-1].cur;
	while(i){
		i=L[i].cur;
		j++;
	}
	return j;
}
Status GetSLElem(SLinkList L, int i, ElemType *e){
	int l, k=MAXSIZE-1;
	if(i<1||i>SLListLength(L)){
		return ERROR;
	}
	for(l=1;l<=i;l++){
		k=L[k].cur;
	}
	*e=L[k].data;
	return OK;
}
int LocateSLElem(SLinkList L, ElemType e){
	int i = L[MAXSIZE-1].cur;
	/*while(i){
		if(e == L[i].data){
			return i;
		}
		i = L[i].cur;
	}*/
	while(i && L[i].data != e){
		i=L[i].cur;
	}
	return i;
}
Status PriorSLElem(SLinkList L,ElemType cur_e, ElemType *pre_e){
	int j,i = L[MAXSIZE-1].cur;
	do{
		j=i;
		i=L[i].cur;
	}while(i&&cur_e!=L[i].data);
	if(i)
	{
		*pre_e=L[j].data;
		return OK;
	}
	return ERROR;
}
Status NextSLElem(SLinkList L, ElemType cur_e, ElemType *next_e){
	int j, i =LocateSLElem(L, cur_e);
	if(i){
		j=L[i].cur;
		if(j){
			*next_e=L[j].data;
			return OK;
		}
	}
	return ERROR;
}
Status SLListInsert(SLinkList L, int i, ElemType e){
	int l, j, k= MAXSIZE-1;
	if(i<1||i>SLListLength(L)+1){
		return ERROR;
	}
	j=SLMalloc(L);
	if(j){
		L[j].data = e;
		for(l=1;l<i;l++){
			k=L[k].cur;
		}
		L[j].cur=L[k].cur;
		L[k].cur = j;
		return OK;
	}
	return ERROR;
}
Status SLListDelete(SLinkList L, int i, ElemType *e){
	int j,k=MAXSIZE-1;
	if(i<1||i>SLListLength(L)){
		return ERROR;
	}
	for(j=1;j<i;j++){
		k=L[k].cur;
	}

	j=L[k].cur;
	L[k].cur = L[j].cur;
	*e = L[j].data;
	SLFree(L,j);

	return OK;
}
Status SLListTraverse(SLinkList L, void(*vi)(ElemType, int)){
	int i = L[MAXSIZE-1].cur;

	while(i){
		vi(L[i].data, L[i].cur);
		i = L[i].cur;
	}

	return OK;
}