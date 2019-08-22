#include"SList.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
void SListInit(SList*list)
{
	assert(list);
	list->head = NULL;
}
void SListDeestory(SList *list) //Ïú»Ù
{

}
SListNode* BuySListNode(SLDataType data)
{
	SListNode *node = (SListNode*)malloc(sizeof(SListNode));
	assert(node);
	node->data = data;
	node->next = NULL;
	return node;
}
void SListPushFront(SList *list, SLDataType data) //Í·²å
{
	assert(list);
	SListNode* node = BuySListNode(data);
	 node->next = list->head;
	 list->head = node;
}

void SListPushBack(SList *list, SLDataType data)   //Î²²å
{
	assert(list);
	if (list->head == NULL) {
		SListPushFront(list, data);
		return;
	}
	SListNode*cur = list->head;
	while(cur->next)
		{
			cur = cur->next;
	    }
	SListNode* node = BuySListNode(data);
	cur->next = node;
}
void SListPopFront(SList *list)    // Í·É¾
{
	assert(list);
	if (list->head == NULL) {
		return;
	}
	SListNode* cur = list->head;
	list->head = cur->next;
	free(cur);
}
void  SListPopBack(SList * list)   //Î²É¾
{
	assert(list);
	assert(list->head != NULL);
	if (list->head->next == NULL) {
		SListPopFront(list);
		return;
	}
	SListNode* cur = list->head;
	while (cur->next->next)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}
SListNode* SListFind(SList *list, SLDataType data)        //²éÕÒ
{
	assert(list);
	for (SListNode * cur = list->head; cur != NULL; cur = cur->next)
	{
		if (data == cur->data) {
			return cur;
		}
	}
	return NULL;
}
void SListInserAfter(SListNode *pos, SLDataType data)
{
	SListNode *node = BuySListNode(data);
	node->next = pos->next;
	pos->next = node;
}
void SListEraseAfter(SListNode *pos)
{
	SListNode*cur = pos->next;
	pos->next = cur->next;
	free(cur);
}
void SListRemove(SList *list, SLDataType data)
{
	assert(list);
	SListNode* cur = list->head;
	SListNode* pre = NULL;
	while (cur != NULL && cur->data != data) {
		pre = cur;
		cur = cur->next;
	}
	if (cur == NULL) {
		return;
	}
	if (pre == NULL) {
		SListPopFront(list);
		return;
	}
	pre->next = cur->next;
	free(cur);
}

void SListPrint(SList*list)
{
	for (SListNode*cur = list->head; cur != NULL; cur = cur->next)
	{
		printf("%d-->", cur->data);
	}
	printf("NULL\n");
}