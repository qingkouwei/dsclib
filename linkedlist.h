#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include "Common.h"

typedef int ElemType;

typedef struct LLNode{
	ElemType data;
	struct LLNode *next;
}*Link, *Position;

typedef struct{
	Link head, tail;

	int len;
}LinkedList;

/**
 * malloc node which valued e and pointed by p
 * @param p  malloc space address
 * @param e malloc space value
 * @return SUCCESS if malloc success and ERROR if failed
 *
*/
Status MakeNode(Link *p, ElemType e);
/**
 * free node which pointed by p
 * @param p  malloc space address
 *
*/
void FreeNode(Link *p);

/**
 * make a empty LinkedList L
 * @param L  LinkedList pointer
 * @return SUCCESS if malloc success and ERROR if failed
 *
*/
Status InitList(LinkedList *L);
/**
 * destroy a LinkedList L
 * @param L  LinkedList pointer
 * @return OK if malloc success and ERROR if failed
 *
*/
Status DestroyList(LinkedList *L);
/**
 * clear a LinkedList L to empty
 * @param L  LinkedList pointer
 * @return OK if malloc success and ERROR if failed
 *
*/
Status ClearList(LinkedList *L);
/**
 * insert a node s to LinkedList head
 * @param L  LinkedList pointer
 * @param s node to be inserted  
 * @return OK if malloc success and ERROR if failed
 *
*/
Status InsFirst(LinkedList *L, Link s);
/**
 * delete a node s from LinkedList head
 * @param L  LinkedList pointer
 * @param q a pointer that pointe to has deleted node
 * @return OK if malloc success and ERROR if failed
 *
*/
Status DelFirst(LinkedList *L, Link *q);
/**
 * append a node s to LinkedList
 * @param L LinkedList pointer
 * @param s node to be inserted 
 * @return OK if malloc success and ERROR if failed
 *
*/
Status Append(LinkedList *L, Link s);
/**
 * remove a node s from LinkedList tail
 * @param L LinkedList pointer
 * @param q a pointer that pointe to has removed node
 * @return OK if malloc success and ERROR if failed
 *
*/
Status Remove(LinkedList *L, Link *q);

/**
 * insert s point LinkedList(not only s node) before p node
 * @param L LinkedList pointer
 * @param p insert LinkedList before p
 * @param s LinkedList to be inserted 
 * @return OK if insert success and ERROR if failed
 *
*/
Status InsBefore(LinkedList *L, Link *p, Link s);
/**
 * insert s point LinkedList(not only s node) after p node
 * @param L LinkedList pointer
 * @param p insert LinkedList after p
 * @param s LinkedList to be inserted 
 * @return OK if insert success and ERROR if failed
 *
*/
Status InsAfter(LinkedList *L, Link *p, Link s);
/**
 * set value e for node p
 * @param p a node that will be setted value
 * @param e value
 * @return OK if set value success and ERROR if failed
 *
*/
Status SetCurElem(Link p, ElemType e);
/**
 * get value from node p
 * @param p a node that will be got value
 * @return node p value
 *
*/
ElemType GetCurElem(Link p);
/**
 * judge a LinkedList is empty
 * @param l 
 * @return TRUE LinkedList is empty else FALSE
 *
*/
Status ListEmpty(LinkedList L);
/**
 * get LinkedList length
 * @param L
 * @return LinkedList length
 *
*/
int ListLength(LinkedList L);
/**
 * get LinkedList Head Node
 * @param L
 * @return LinkedList Head Node
 *
*/
Position GetHead(LinkedList L);
/**
 * get LinkedList last Node
 * @param L
 * @return LinkedList Head Node
 *
*/
Position GetLast(LinkedList L);
/**
 * get node p prior node
 * @param L
 * @param p
 * @return 
 *
*/
Position PriorPos(LinkedList L, Link p);
/**
 * get node p next node
 * @param p
 * @return
 *
*/
Position NextPos(Link p);
/**
 * @param 
 * @param
 * @param
 * @return 
 */
Status LocatePos(LinkedList L, int i, Link *p);
/**
 * @param 
 * @param
 * @param
 * @return 
 */
Position LocateElem(LinkedList L, ElemType e, Status(*compare)(ElemType, ElemType));
/**
 * @param 
 * @param
 * @return 
 */
Status ListTraverse(LinkedList L, void(*visit)(ElemType));


#endif