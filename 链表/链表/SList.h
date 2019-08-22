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
void SListPushFront(SList *list, SLDataType data); //ͷ��
void SListPushBack(SList *list, SLDataType data);   //β��
void SListPopFront(SList *list);     // ͷɾ
void SListPopBack(SList *list);      // βɾ
SListNode* SListFind(SList *list, SLDataType data);        //����

//��pos�����������½ڵ�
void SListInserAfter(SListNode *pos, SLDataType data);    

//ɾ��pos���������Ľ��
void SListEraseAfter(SListNode *pos);

//ɾ����һ��������data���
void SListRemove(SList *list, SLDataType data);

void SListDeestory(SList *list); //����
void SListPrint(SList *list);
SListNode* BuySListNode(SLDataType data);