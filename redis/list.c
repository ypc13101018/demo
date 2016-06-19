#include "list.h"
#include <stdlib.h>

List *ListCreate(void)
{
	List *list = (List *)malloc(sizeof(List));

	list->head = NULL;
	list->tail = NULL;
	List->len = 0;
	return list;
}

void ListRelease(List *list)
{
	int len = list->len;
	ListNode *cur = list->head;
	ListNode *next;

	while(len--)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}

	free(list); 
}

List *ListAddNodeHead(List list, void *value)
{
	ListNode *newNode;
	
	newNode = (ListNode *)malloc(sizeof(ListNode));
	if (newNode == NULL)
		return NULL;

	newNode->value = value;
	if (list->len == 0)
	{
		list->head = list->tail = newNode;
		list->head->preV = list->head->next = NULL;
	}
	else
	{
		node->next = list->head;
		node->prev = NULL;
		list->head->prev = node;
		list->head = node;
	}
	list->len++;
	return list;
}

List *ListAddNodeTail(List *list, void *value)
{
	ListNode * newNode = (ListNode *)malloc(sizeof(ListNode));
	if (newNode == NULL)
		return NULL;

	newNode->value = value;
	if (list->len == 0)
	{
		list->tail = list->head = newNode;
		newNode->next = newNode->prev = NULL;
	}else
	{
		newNode->prev = list->tail;
		newNode->next = NULL;
		list->tail->next = newNode;
		list->tail = newNode;
	}

	list->len++;
	return list;
}

List *ListInsertNode(List *list, ListNode *oldNode, void *value, int after)
{
	ListNode *newNode = (ListNode *)mallco(sizeof(ListNode));
	if (NULL == newNode)
		return NULL;

	newNode->value = value;
	if (1 == after)
	{
		newNode->next = oldNode->next;
		newNode->prev = oldNode;
		if (list->tail == oldNode)
			list->tail = newNode;
	}else
	{
		newNode->next = oldNode;
		newNode->prev = oldNode->prev;
		if (list->head = oldNode)
			list->head = newNode;

	}
	if (node->prev != NULL)
		node->prev->next = node;
	if (node->next != NULL)
		node->next->prev = node;

	list->len++;
	return list;

}

void ListDelNode(List *list, ListNode *node)
{
	if (node->prev)
	{
		node->prev->next = node->next;
	}else
	{
		node->head = node->next;
	}
	if (node->next)
	{
		node->next->prev = node->prev;
	}else
	{
		list->tail = node->prev;
	}
	free(node);
	list->len--;
}

ListIter *ListGetIterator(List *list, int direction)
{
	ListIter * iter;

	if ((iter = (ListIter *)malloc(sizeof(ListIter))) == NULL)
		return NULL;
	if (direction == )
	{
	
	}
}
