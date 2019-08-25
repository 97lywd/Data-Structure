#include"CriPath.h"
int LocateVex(ALGraph G, VertexType u) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vertices[i].data == u) {
			return i;
		}
	}
	return -1;
}
//创建AOE网，构建邻接表
void CreateAOE(ALGraph **G) {
	*G = (ALGraph*)malloc(sizeof(ALGraph));

	scanf("%d,%d", &((*G)->vexnum), &((*G)->arcnum));
	for (int i = 0; i < (*G)->vexnum; i++) {
		scanf("%d", &((*G)->vertices[i].data));
		(*G)->vertices[i].firstarc = NULL;
	}
	VertexType initial, end, dut;
	for (int i = 0; i < (*G)->arcnum; i++) {
		scanf("%d,%d,%d", &initial, &end, &dut);

		ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = LocateVex(*(*G), end);
		p->nextarc = NULL;
		p->dut = dut;

		int locate = LocateVex(*(*G), initial);
		p->nextarc = (*G)->vertices[locate].firstarc;
		(*G)->vertices[locate].firstarc = p;
	}
}

//初始化栈结构
void initStack(stack* *S) {
	(*S) = (stack*)malloc(sizeof(stack));
	(*S)->next = NULL;
}
//判断栈是否为空
bool StackEmpty(stack S) {
	if (S.next == NULL) {
		return true;
	}
	return false;
}
//进栈
void push(stack *S, VertexType u) {
	stack *p = (stack*)malloc(sizeof(stack));
	p->data = u;
	p->next = NULL;
	p->next = S->next;
	S->next = p;
}
//出栈
void pop(stack *S, VertexType *i) {
	stack *p = S->next;
	*i = p->data;
	S->next = S->next->next;
	free(p);
}
//统计各顶点的入度
void FindInDegree(ALGraph G, int indegree[]) {
	
	for (int i = 0; i < G.vexnum; i++) {
		indegree[i] = 0;
	}
	//遍历邻接表，根据各链表中结点的数据域存储的各顶点位置下标，在indegree数组相应位置+1
	for (int i = 0; i < G.vexnum; i++) {
		ArcNode *p = G.vertices[i].firstarc;
		while (p) {
			indegree[p->adjvex]++;
			p = p->nextarc;
		}
	}
}

bool TopologicalOrder(ALGraph G) {
	int indegree[MAX_VERTEX_NUM];
	FindInDegree(G, indegree);
	stack *S;
	initStack(&S);
	for (int i = 0; i < G.vexnum; i++) {
		ve[i] = 0;
	}
	for (int i = 0; i < G.vexnum; i++) {
		if (!indegree[i]) {
			push(S, i);
		}
	}
	int count = 0;
	//栈为空为结束标志
	while (!StackEmpty(*S)) {
		int index;
		//弹栈，并记录栈中保存的顶点所在邻接表数组中的位置
		pop(S, &index);
		//压栈，为求各边的最晚开始时间做准备
		push(T, index);
		++count;
		for (ArcNode *p = G.vertices[index].firstarc; p; p = p->nextarc) {

			VertexType k = p->adjvex;

			if (!(--indegree[k])) {
				//顶点入度为0，入栈
				push(S, k);
			}
		
			if (ve[index] + p->dut > ve[k]) {
				ve[k] = ve[index] + p->dut;
			}
		}
	}
	
	if (count < G.vexnum) {
		printf("该图有回路");
		return false;
	}
	return true;
}

void CriticalPath(ALGraph G) {
	if (!TopologicalOrder(G)) {
		return;
	}
	for (int i = 0; i < G.vexnum; i++) {
		vl[i] = ve[G.vexnum - 1];
	}
	int j, k;
	while (!StackEmpty(*T)) {
		pop(T, &j);
		for (ArcNode* p = G.vertices[j].firstarc; p; p = p->nextarc) {
			k = p->adjvex;
			//构建Vl数组，在初始化时，Vl数组中每个单元都是18，如果每个边的汇点-边的权值比源点值小，就保存更小的。
			if (vl[k] - p->dut < vl[j]) {
				vl[j] = vl[k] - p->dut;
			}
		}
	}
	for (j = 0; j < G.vexnum; j++) {
		for (ArcNode*p = G.vertices[j].firstarc; p; p = p->nextarc) {
			k = p->adjvex;
			//求各边的最早开始时间e[i],等于ve数组中相应源点存储的值
			int ee = ve[j];
			//求各边的最晚开始时间l[i]，等于汇点在vl数组中存储的值减改边的权值
			int el = vl[k] - p->dut;
			//判断e[i]和l[i]是否相等，如果相等，该边就是关键活动，相应的用*标记；反之，边后边没标记
			char tag = (ee == el) ? '*' : ' ';
			printf("%3d%3d%3d%3d%3d%2c\n", j, k, p->dut, ee, el, tag);
		}
	}
}



//
//9, 11
//1
//2
//3
//4
//5
//6
//7
//8
//9
//1, 2, 6
//1, 3, 4
//1, 4, 5
//2, 5, 1
//3, 5, 1
//4, 6, 2
//5, 7, 9
//5, 8, 7
//6, 8, 4
//7, 9, 2
//8, 9, 4
