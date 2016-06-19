#ifndef __LIST_H
#define __LIST_H
typedef struct ListNode
{
	struct ListNode *prev;
	struct ListNode *next;
	void * value;
}ListNode;

typedef struct List
{
	ListNode *head;
	ListNode *tail;
	int len;
}list;

typedef struct ListIter
{
	ListNode *next;
	int direction;
}





#endif
