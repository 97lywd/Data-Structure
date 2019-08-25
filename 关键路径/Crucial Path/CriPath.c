#include"CriPath.h"
int LocateVex(ALGraph G, VertexType u) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vertices[i].data == u) {
			return i;
		}
	}
	return -1;
}
//����AOE���������ڽӱ�
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

//��ʼ��ջ�ṹ
void initStack(stack* *S) {
	(*S) = (stack*)malloc(sizeof(stack));
	(*S)->next = NULL;
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(stack S) {
	if (S.next == NULL) {
		return true;
	}
	return false;
}
//��ջ
void push(stack *S, VertexType u) {
	stack *p = (stack*)malloc(sizeof(stack));
	p->data = u;
	p->next = NULL;
	p->next = S->next;
	S->next = p;
}
//��ջ
void pop(stack *S, VertexType *i) {
	stack *p = S->next;
	*i = p->data;
	S->next = S->next->next;
	free(p);
}
//ͳ�Ƹ���������
void FindInDegree(ALGraph G, int indegree[]) {
	
	for (int i = 0; i < G.vexnum; i++) {
		indegree[i] = 0;
	}
	//�����ڽӱ����ݸ������н���������洢�ĸ�����λ���±꣬��indegree������Ӧλ��+1
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
	//ջΪ��Ϊ������־
	while (!StackEmpty(*S)) {
		int index;
		//��ջ������¼ջ�б���Ķ��������ڽӱ������е�λ��
		pop(S, &index);
		//ѹջ��Ϊ����ߵ�����ʼʱ����׼��
		push(T, index);
		++count;
		for (ArcNode *p = G.vertices[index].firstarc; p; p = p->nextarc) {

			VertexType k = p->adjvex;

			if (!(--indegree[k])) {
				//�������Ϊ0����ջ
				push(S, k);
			}
		
			if (ve[index] + p->dut > ve[k]) {
				ve[k] = ve[index] + p->dut;
			}
		}
	}
	
	if (count < G.vexnum) {
		printf("��ͼ�л�·");
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
			//����Vl���飬�ڳ�ʼ��ʱ��Vl������ÿ����Ԫ����18�����ÿ���ߵĻ��-�ߵ�Ȩֵ��Դ��ֵС���ͱ����С�ġ�
			if (vl[k] - p->dut < vl[j]) {
				vl[j] = vl[k] - p->dut;
			}
		}
	}
	for (j = 0; j < G.vexnum; j++) {
		for (ArcNode*p = G.vertices[j].firstarc; p; p = p->nextarc) {
			k = p->adjvex;
			//����ߵ����翪ʼʱ��e[i],����ve��������ӦԴ��洢��ֵ
			int ee = ve[j];
			//����ߵ�����ʼʱ��l[i]�����ڻ����vl�����д洢��ֵ���ıߵ�Ȩֵ
			int el = vl[k] - p->dut;
			//�ж�e[i]��l[i]�Ƿ���ȣ������ȣ��ñ߾��ǹؼ������Ӧ����*��ǣ���֮���ߺ��û���
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
