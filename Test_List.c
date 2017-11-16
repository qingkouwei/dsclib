#include "alist.h"
#include "llist.h"
#include "sllist.h"
#include "linkedlist.h"

typedef int ElemType;

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

static enum {
	SqListT, LListT, SLListT, DuLListT, CLListT, LinkedListT
} listType = LinkedListT;

Status compare(ElemType e1, ElemType e2) {
	if (e1 == e2 * e2) {
		return TRUE;
	}
	return FALSE;
}
Status compare2(ElemType e1, ElemType e2) {
	if (e1 == e2) {
		return TRUE;
	}
	return FALSE;
}

static void usage(char * argv[]) {
	printf("Usage %s [Options]\n"
	       "test list struct.\n"
	       "\n"
	       "Options:\n"
	       "--help\n"
	       "    Show this message.\n"
	       "--type\n"
	       "    list type.\n"
	       "\n"
	       "list type:\n"
	       "SqList: array list.\n"
	       "LList: linked list.\n"
	       "SLList: static linked list\n"
	       "DuLList: double linked list.\n"
	       "CLList: circular linked list.\n"
	       "\n"
	       "For example:\n"
	       " %s --type SqList\n",
	       argv[0], argv[0]
	      );
}
static Status comp(ElemType c1, ElemType c2) {
	if (c1 == c2) {
		return TRUE;
	}
	return FALSE;
}
static void visit(ElemType e) {
	printf("%d ", e);
}
static void visitn(ElemType c) {
	printf("%d\n", c);
}
static void visit2(ElemType c, int cur) {
	printf("%d - %d\n", c, cur);
}


static void testSLList() {
	printf("\n\nstart test static linked list:\n\n");
	ElemType e, e0;
	Status status;
	int j, k;
	SLinkList L;
	status = InitSLList(L);
	if (!status) {
		printf("init static list failed\n");
		return;
	}
	for (j = 1; j <= 5; j++) {
		status = SLListInsert(L, 1, j);
	}
	printf("\n");
	printf("after insert 5 data into list head: L.elems = \n");
	SLListTraverse(L, visit2);
	printf("\n");

	status = SLListEmpty(L);
	printf("L is empty? status = %d(1:yes 0:no)\n", status);
	status = ClearSLList(L);
	printf("after clear L: ");
	SLListTraverse(L, visit2);
	status = SLListEmpty(L);
	printf("\nafater claer ,L is empty? status = %d(1:yes 0:no)\n", status);

	for (j = 1; j <= 10; j++) {
		SLListInsert(L, j, j);
	}
	printf("\n");
	printf("after insert 10 data into list tail: L.elems = \n");
	SLListTraverse(L, visit2);
	printf("\n");

	GetSLElem(L, 5, &e);
	printf("5th data is : %d\n\n", e);

	for (j = 0; j <= 1; j++) {
		k = LocateSLElem(L, j);
		if(k){
			printf("value %d elem in list locate is %d\n", j, k);
		}else{
			printf("has no elem %d \n", j);
		}
	}
	printf("\n");
	for (j = 1; j <= 2; j++) {
		GetSLElem(L, j, &e0);
		status = PriorSLElem(L, e0, &e);
		if (status == ERROR) {
			printf("elem %d has no prior\n", e0);
		} else {
			printf("elem %d prior is %d\n", e0, e);
		}
	}
	printf("\n");
	for(j = SLListLength(L) - 1; j<= SLListLength(L); j++){
		GetSLElem(L, j, &e0);
		status = NextSLElem(L, e0, &e);
		if(!status){
			printf("elem %d has no next\n", e0);
		}else{
			printf("elem %d next is :%d\n", e0, e);
		}
	}
	printf("\n");
	k = SLListLength(L);
	for (j = k + 1; j >= k; j--) {
		status = SLListDelete(L, j, &e);
		if (status == ERROR) {
			printf("delete %d elem failed.\n", j);
		} else {
			printf("delete data is :%d\n", e);
		}
	}
	printf("\nlist is: \n");
	SLListTraverse(L, visit2);
}

static void testLList() {
	printf("\nstart test LList..\n");
	LinkList L;
	ElemType e, e0;
	Status status;
	int j, k;
	status = InitLList(&L);
	if (!status) {
		printf("init list failed\n");
		return;
	}
	for (j = 1; j <= 5; j++) {
		status = LListInsert(L, 1, j);
	}
	printf("test insert\n");
	printf("after insert 5 data:\n");
	LListTraverse(L, visitn);
	status = LListEmpty(L);
	printf("L is empty? status = %d(1:yes 0:no)\n", status);
	status = ClearLList(L);
	printf("clear L empty: L = ");
	LListTraverse(L, visit);
	printf("\n");
	status = LListEmpty(L);
	printf("L is empty? status = %d(1:yes 0:no)\n", status);
	for (j = 1; j <= 10; j++) {
		LListInsert(L, j, j);
	}
	printf("after insert 1~10 into tail L is :\n");
	LListTraverse(L, visit);
	printf("\n");
	GetElemL(L, 5, &e);
	printf("fifthly elem is : %d\n", e);
	for (j = 0; j <= 1; j++) {
		k = LocateElemL(L, j, comp);
		if (k) {
			printf("%d location is %d\n", k, j);
		} else {
			printf("has not location %d elem\n", j);
		}
	}

	printf("\ntest prior:\n");
	for (j = 1; j <= 2; j++) {
		GetElemL(L, j, &e0);
		status = PriorElemL(L, e0, &e);
		if (status == INFEASIBLE) {
			printf("elem %d has no prior\n", e0);
		} else {
			printf("elem %d prior is %d\n", e0, e);
		}
	}

	printf("\ntest next:\n");
	for (j = LListLength(L) - 1; j <= LListLength(L); j++) {
		GetElemL(L, j, &e0);
		status = NextElemL(L, e0, &e);
		if (status == INFEASIBLE) {
			printf("elem %d has no next \n", e0);
		} else {
			printf("elem %d next is %d\n", e0, e);
		}
	}

	printf("\n get List delete:\n");
	k = LListLength(L);
	for (j = k + 1; j >= k; j--) {
		status = LListDelete(L, j, &e);
		if (status == ERROR) {
			printf("delete %d elem failed!\n", j);
		} else {
			printf("delete elem value is :%d\n", e);
		}
	}
	printf("printf delete elems L:");
	LListTraverse(L, visit);
	printf("\n");
	DestroyLList(&L);
	printf("destroy list is : L = %p\n", &L);

}
static void testSqList() {
	printf("\nstart test array list..\n");
	ElemType e, e0;
	Status status;
	int j, k;
	SqList L;
	status = InitList_Sq(&L);
	if (!status) {
		printf("init static list failed\n");
		return;
	}
	for (j = 1; j <= 5; j++) {
		status = List_SqInsert(&L, 1, j);
	}
	printf("\n");
	printf("after insert 5 data into list head: L.elems = ");
	List_SqTraverse(L, visit);
	printf("\n");

	status = List_SqEmpty(L);
	printf("L is : status = %d(1:yes 0:no)\n", status);
	status = ClearList_Sq(&L);
	printf("after clear L: L.elems=%p, L.length = %d, L.listSize = %d\n", L.elems, L.length, L.listSize);
	status = List_SqEmpty(L);
	printf("fater claer ,L is : status = %d(1:yes 0:no)\n", status);

	for (j = 1; j <= 10; j++) {
		List_SqInsert(&L, j, j);
	}
	printf("\n");
	printf("after insert 10 data into list tail: L.elems = ");
	for (j = 1; j <= List_SqLength(L); j++) {
		printf("%d ", *(L.elems + j - 1));
	}
	printf("\n");

	GetElem_Sq(L, 5, &e);
	printf("5 data is : %d\n", e);

	for (j = 1; j <= 2; j++) {
		GetElem_Sq(L, j, &e0);
		status = PriorElem_Sq(L, e0, &e);
		if (status == INFEASIBLE) {
			printf("elem %d has no prior\n", e0);
		} else {
			printf("elem %d prior is %d\n", e0, e);
		}
	}
	k = List_SqLength(L);
	for (j = k + 1; j >= k; j--) {
		status = List_SqDelete(&L, j, &e);
		if (status == ERROR) {
			printf("delete %d elem failed.\n", j);
		} else {
			printf("delete data is :%d\n", e);
		}
	}
}

void testLinkedList() {
	printf("\nstart test linkedlist..\n");
	Link p, h;
	LinkedList L;
	Status status;
	int j, k;
	status = InitList(&L);
	if (!status) {
		exit(FALSE);
	}
	for (j = 1; j <= 2; j++) {
		MakeNode(&p, j);
		InsFirst(&L, p);
	}
	for (j = 0; j <= 2; j++) {
		p = LocateElem(L, j, compare2);
		if (p) {
			printf("linkedlist has elem %d\n", j);
		} else {
			printf("linkedlist has no elem %d\n", j);
		}
	}
}
int main(int argc, char *argv[]) {
	static const struct option longOptions[] = {
		{"help",         no_argument,        NULL,      'h'},
		{"type",         required_argument,  NULL,      't'},
		{NULL,           0,                  NULL,       0 }
	};

	printf("\nlist arithmetic test\n");
	if (argc <= 1) {
		usage(argv);
		exit(-1);
	}
	while (1) {
		int optionIndex = 0;
		int ic = getopt_long(argc, argv, "", longOptions, &optionIndex);
		if (ic == -1) {
			break;
		}
		switch (ic) {
		case 'h':
			usage(argv);
			return 0;
		case 't':
			if (strcmp(optarg, "SqList") == 0) {
				listType = SqListT;
			} else if (strcmp(optarg, "LList") == 0) {
				listType = LListT;
			} else if (strcmp(optarg, "SLList") == 0) {
				listType = SLListT;
			} else if (strcmp(optarg, "DuLList") == 0) {
				listType = DuLListT;
			} else if (strcmp(optarg, "CLList") == 0) {
				listType = CLListT;
			} else if (strcmp(optarg, "LinkedList") == 0) {
				listType = LinkedListT;
			} else {
				printf("unsupported list type: %s !!!\n", optarg);
				return 2;
			}
			break;
		default:
			if (ic != '?') {
				printf("getopt_long returned unexpected value 0x%x\n", ic);
			}
			return 2;
		}
	}
	printf("list type is :%d\n", listType);

	switch (listType) {
	case SqListT:
		testSqList();
		break;
	case LListT:
		testLList();
		break;
	case SLListT:
		testSLList();
		break;
	case DuLListT:

		break;
	case CLListT:

		break;
	case LinkedListT:
		testLinkedList();
		break;
	}

	return 0;
}