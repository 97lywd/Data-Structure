#include"CriPath.h"
int main() {
	ALGraph *G;
	CreateAOE(&G);
	initStack(&T);
	TopologicalOrder(*G);
	CriticalPath(*G);
	system("pause");
	return  0;
}