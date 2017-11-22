#include "polynomial.h"
#include "stdio.h"


static int cmp(void *a, void *b)
{
	term *t1 = (term *)a;
	term *t2 = (term *)b;
	if ((*t1).expn == (*t2).expn) {
		return 0;
	} else {
		return ((*t1).expn - (*t2).expn) / abs((*t1).expn - (*t2).expn);
	}
}
static int compare(term *a, term *b) {
	if ((*a).expn == (*b).expn) {
		return TRUE;
	} else {
		return FALSE;
	}
}
void assignTerm(void *e1, void *e2) {
	term *p1 = (term *)e1;
	term *p2 = (term *)e2;
	p1->coef = p2->coef;
	p1->expn = p2->expn;
}

/**
 * 按有序判断函数compare()的约定,将值为的结点插入或合并到升序链表的适当位置
 *
 *
 */
Status OrderInsertMerge(polynomial *P, term e, int(*compare)(void*, void*)) {
	Iterator q, s;
	float sum;
	if (LocateElemP(*P, &e, &q, cmp)) {
		term *t = (term *)GetCurElem(q);
		sum = t->coef + e.coef;
		t->coef = sum;
		SetCurElem(q, t, assignTerm);
		if (sum == 0) {
			s = PriorPos(*P, q);
			if (!s) {
				s = GetHead(*P);
			}
			DelFirstH(*P, s, &q);
			FreeNode(&q);
		}
		return OK;
	} else {
		if (MakeNode(&s, &e, sizeof(term), assignTerm)) {
			InsFirstH(*P, q, s);
			return OK;
		} else {
			return ERROR;
		}
	}

}
void Opposite(polynomial Pa) {
	Iterator q;
	term *t;
	q = GetHead(Pa);
	while (NextPos(q)) {
		q = NextPos(q);
		t = (term*)GetCurElem(q);
		t->coef = -1 * t->coef;
		SetCurElem(q, t, assignTerm);

	}
}

void CreatePolyn(polynomial *P, int m) {
	Iterator q, s;
	term e;
	int i;
	InitList(P, sizeof(term));
	printf("please enter %d expn, exponent:\n", m);
	for (i = 1; i <= m; i++) {
		scanf("%f %d", &e.coef, &e.expn);
		if (!LocateElemP(*P, &e, &q, cmp)) {
			if (MakeNode(&s, &e, sizeof(term), assignTerm)) {
				InsFirstH(*P, q, s);
			}
		}
	}


}
void DestroyPolyn(polynomial *P) {
	DestroyList(*P);

}
void PrintPolyn(polynomial P) {
	Iterator q = GetHead(P);
	q = NextPos(q);
	printf("    coef    expn\n");
	while (q) {
		term *t = (term *)(GetCurElem(q));
		printf("%f    %d\n", t->coef, t->expn);
		q = NextPos(q);
	}
}
int PolynLength(polynomial P) {
	return ListLength(P);
}
void AddPolyn(polynomial *Pa, polynomial *Pb) {
	Iterator ha = GetHead(*Pa);
	Iterator hb = GetHead(*Pb);
	Iterator qa = NextPos(ha);
	Iterator qb = NextPos(hb);
	float sum = 0;
	while (qa && qb) {
		term *da = (term*)GetCurElem(qa);
		term *db = (term*)GetCurElem(qb);
		switch (cmp(da, db)) {
		case -1:
			ha = qa;
			qa = NextPos(ha);
			break;
		case 0:
			sum = da->coef + db->coef;
			if (sum != 0) {
				da->coef = sum;
				SetCurElem(qa, da, assignTerm);
				ha = qa;
			} else {
				DelFirstH(*Pa, ha, &qa);
				FreeNode(&qa);
			}
			DelFirstH(*Pb, hb, &qb);
			FreeNode(&qb);
			qb = NextPos(hb);
			qa = NextPos(ha);
			break;
		case 1:
			DelFirstH(*Pb, hb, &qb);
			InsFirstH(*Pa, ha, qb);
			qb = NextPos(hb);
			qa = NextPos(ha);
			break;
		}
	}
	if (!ListEmpty(*Pb)) {
		Append(*Pa, qb);
	}
	FreeNode(&hb);

}
void AddPolyn2(polynomial *Pa, polynomial *Pb) {
	Iterator qb;
	term *b;
	qb = GetHead(*Pb);
	qb = NextPos(qb);
	while (qb)
	{
		b = (term *)GetCurElem(qb);
		OrderInsertMerge(Pa, *b, cmp);
		qb = NextPos(qb);
	}
	DestroyPolyn(Pb);
}

void SubtractPolyn(polynomial *Pa, polynomial *Pb)
{
	Opposite(*Pb);
	AddPolyn(Pa, Pb);

}
void MultiplyPolyn(polynomial *Pa, polynomial *Pb) {
	polynomial Pc;
	Iterator qa, qb;
	term *a, *b, c;
	InitList(&Pc,sizeof(term));
	qa = GetHead(*Pa);
	qa = NextPos(qa);
	while (qa) {
		a = (term*)GetCurElem(qa);
		qb = GetHead(*Pb);
		qb = NextPos(qb);
		while (qb) {
			b = (term*)GetCurElem(qb);
			//printf("a coef:%f,b coef:%f, c coef:%f\n", a->coef, b->coef,c.coef);
			c.coef = (a->coef)*(b->coef);
			c.expn = (a->expn) + (b->expn);
			OrderInsertMerge(&Pc, c, cmp);
			qb = NextPos(qb);
		}
		qa = NextPos(qa);
	}
	DestroyPolyn(Pb);
	ClearList(*Pa);
	SetHead(*Pa, GetHead(Pc));
	SetTail(*Pa, GetLast(Pc));
	setListLength(*Pa, ListLength(Pc));
}