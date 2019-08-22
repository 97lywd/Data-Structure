#pragma once
typedef int SLDataType;
typedef struct SListNode {
	SLDataType data;
	struct SListNode *next;
}SListNode;

typedef struct SList {
	SListNode* head;
}SList;

void SListInit(SList *list);
void SListPushFront(SList *list, SLDataType data); //头插
void SListPushBack(SList *list, SLDataType data);   //尾插
void SListPopFront(SList *list);     // 头删
void SListPopBack(SList *list);      // 尾删
SListNode* SListFind(SList *list, SLDataType data);        //查找

//在pos这个结点后插入新节点
void SListInserAfter(SListNode *pos, SLDataType data);    

//删除pos这个结点后面的结点
void SListEraseAfter(SListNode *pos);

//删除第一个遇到的data结点
void SListRemove(SList *list, SLDataType data);

void SListDeestory(SList *list); //销毁
void SListPrint(SList *list);
SListNode* BuySListNode(SLDataType data);