#include"TopoSort.h"

int main() {
	ALGraph *G;
	CreateAOV(&G);
	TopologicalSort(*G);
	system("pause");
	return  0;
}