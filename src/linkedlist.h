#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include "Common.h"

typedef struct node* Iterator;
typedef struct list* LinkedList;
/**
 * malloc node which valued e and pointed by p
 * @param p  malloc space address
 * @param e malloc space value
 * @return SUCCESS if malloc success and ERROR if failed
 *
*/
Status MakeNode(Iterator *p, void *data, int data_size, void (*assign)(void*, void*));
/**
 * free node which pointed by p
 * @param p  malloc space address
 *
*/
void FreeNode(Iterator *p);

/**
 * make a empty LinkedList L
 * @param L  LinkedList pointer
 * @return SUCCESS if malloc success and ERROR if failed
 *
*/
Status InitList(LinkedList *L, int data_size);
/**
 * destroy a LinkedList L
 * @param L  LinkedList pointer
 * @return OK if malloc success and ERROR if failed
 *
*/
Status DestroyList(LinkedList L);
/**
 * clear a LinkedList L to empty
 * @param L  LinkedList pointer
 * @return OK if malloc success and ERROR if failed
 *
*/
Status ClearList(LinkedList L);
/**
 * insert a node s to LinkedList head
 * h指向L的一个节点,把h当做头结点,将s所指节点插入在第一个结点之前
 * 
 * @param L  LinkedList pointer
 * @param s node to be inserted  
 * @return OK if malloc success and ERROR if failed
 *
*/
Status InsFirstH(LinkedList L, Iterator h, Iterator s);
/**
 * delete a node s from LinkedList head
 * h指向L的一个节点,把h当做头结点,删除链表中第一个结点并以返回
 * 
 * @param L  LinkedList pointer
 * @param q a pointer that pointe to has deleted node
 * @return OK if malloc success and ERROR if failed
 *
*/
Status DelFirstH(LinkedList L, Iterator h, Iterator *q);
/**
 * append a node s to LinkedList
 * @param L LinkedList pointer
 * @param s node to be inserted 
 * @return OK if malloc success and ERROR if failed
 *
*/
/**
 * insert a node s to LinkedList head
 * h指向L的一个节点,把h当做头结点,将s所指节点插入在第一个结点之前
 * 
 * @param L  LinkedList pointer
 * @param s node to be inserted  
 * @return OK if malloc success and ERROR if failed
 *
*/
Status InsFirst(LinkedList L,Iterator s);
/**
 * delete a node s from LinkedList head
 * h指向L的一个节点,把h当做头结点,删除链表中第一个结点并以返回
 * 
 * @param L  LinkedList pointer
 * @param q a pointer that pointe to has deleted node
 * @return OK if malloc success and ERROR if failed
 *
*/
Status DelFirst(LinkedList L,Iterator *q);
/**
 * append a node s to LinkedList
 * @param L LinkedList pointer
 * @param s node to be inserted 
 * @return OK if malloc success and ERROR if failed
 *
*/
Status Append(LinkedList L, Iterator s);
/**
 * remove a node s from LinkedList tail
 * @param L LinkedList pointer
 * @param q a pointer that pointe to has removed node
 * @return OK if malloc success and ERROR if failed
 *
*/
Status Remove(LinkedList L, Iterator *q);

/**
 * insert s point LinkedList(not only s node) before p node
 * @param L LinkedList pointer
 * @param p insert LinkedList before p
 * @param s LinkedList to be inserted 
 * @return OK if insert success and ERROR if failed
 *
*/
Status InsBefore(LinkedList L, Iterator *p, Iterator s);
/**
 * insert s point LinkedList(not only s node) after p node
 * @param L LinkedList pointer
 * @param p insert LinkedList after p
 * @param s LinkedList to be inserted 
 * @return OK if insert success and ERROR if failed
 *
*/
Status InsAfter(LinkedList L, Iterator *p, Iterator s);
/**
 * set value e for node p
 * @param p a node that will be setted value
 * @param e value
 * @return OK if set value success and ERROR if failed
 *
*/
Status SetCurElem(Iterator p, void *e, void (*assign)(void*,void*));
/**
 * get value from node p
 * @param p a node that will be got value
 * @return node p value
 *
*/
void* GetCurElem(Iterator p);
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
void setListLength(LinkedList L, int len);
/**
 * get LinkedList Head Node
 * @param L
 * @return LinkedList Head Node
 *
*/
Iterator GetHead(LinkedList L);
Status SetHead(LinkedList L, Iterator p);
/**
 * get LinkedList last Node
 * @param L
 * @return LinkedList Head Node
 *
*/
Iterator GetLast(LinkedList L);
Status SetTail(LinkedList L, Iterator p);
/**
 * get node p prior node
 * @param L
 * @param p
 * @return 
 *
*/
Iterator PriorPos(LinkedList L, Iterator p);
/**
 * get node p next node
 * @param p
 * @return
 *
*/
Iterator NextPos(Iterator p);
/**
 * @param 
 * @param
 * @param
 * @return 
 */
Status LocatePos(LinkedList L, int i, Iterator *p);
/**
 * @param 
 * @param
 * @param
 * @return 
 */
Iterator LocateElem(LinkedList L, void *e, Status(*compare)(void *, void *));
/**
 * @param 
 * @param
 * @return 
 */
Status ListTraverse(LinkedList L, void(*visit)(void *));

/**
 * 已知L为有序线性链表,将元素e按非降序插入在L中.(用于一元多项式)
 * 
 */
Status OrderInsert(LinkedList L, Iterator s, int (*comp)(void *, void *));

/**
 * 若升序链表L中存在与e满足判定函数compare()取值为0的元素,则q指示L中
 * 第一个值为e的结点的位置,并放回TRUE;否则q指示第一个与e满足判定函数compare()
 * 取值>0的元素的前驱的位置.
 * 
 * 
 */
Status LocateElemP(LinkedList L, void *e, Iterator *q, int(*compare)(void*, void*));


#endif