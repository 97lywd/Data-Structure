#include"SList.h"
#include<stdlib.h>
int main()
{
	SList list;
	SListInit(&list);
	SListPushFront(&list, 1);
	SListPushFront(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPrint(&list);
	SListPopFront(&list);
	SListPrint(&list);
	SListPopBack(&list);
	SListPrint(&list);
	SListNode* n = (SListFind(&list, 3));
	SListInserAfter(n,10);
	SListInserAfter(n, 20);
	SListPrint(&list);
	SListEraseAfter(n);
	SListPrint(&list);
	SListRemove(&list, 1);
	SListRemove(&list, 10);
	SListPrint(&list);
	system("pause");
	return 0;
}