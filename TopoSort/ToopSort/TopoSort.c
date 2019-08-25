#include"TopoSort.h"
//�ҵ������Ӧ���ڽӱ������е�λ���±�
int LocateVex(ALGraph G, VertexType u) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vertices[i].data == u) {
			return i;
		}
	}
	return -1;
}
//����AOV���������ڽӱ�
void CreateAOV(ALGraph **G) {
	*G = (ALGraph*)malloc(sizeof(ALGraph));

	scanf("%d%d", &((*G)->vexnum), &((*G)->arcnum));
	for (int i = 0; i < (*G)->vexnum; i++) {
		scanf("%d", &((*G)->vertices[i].data));
		(*G)->vertices[i].firstarc = NULL;
	}
	VertexType initial, end;
	for (int j = 0; j < (*G)->arcnum; j++) {
		scanf("%d%d", &initial, &end);

		ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = LocateVex(*(*G), end);
		p->nextarc = NULL;

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
//�ж������Ƿ�Ϊ��
bool StackEmpty(stack S) {
	if (S.next == NULL) {
		return true;
	}
	return false;
}
//��ջ����ͷ�巨���½����뵽������
void push(stack *S, VertexType u) {
	stack *p = (stack*)malloc(sizeof(stack));
	p->data = u;
	p->next = NULL;
	p->next = S->next;
	S->next = p;
}
//��ջ������ɾ��������Ԫ����ͬʱ���ͷŸÿռ䣬�����ý���е�������ͨ����ַ��ֵ������i;
void pop(stack *S, VertexType *i) {
	stack *p = S->next;
	*i = p->data;
	S->next = S->next->next;
	free(p);
}
//ͳ�Ƹ���������
void FindInDegree(ALGraph G, int indegree[]) {
	//��ʼ�����飬Ĭ�ϳ�ʼֵȫ��Ϊ0
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
void TopologicalSort(ALGraph G) {
	int indegree[MAX_VERTEX_NUM];//������¼��������ȵ�����
	FindInDegree(G, indegree);//ͳ�Ƹ���������
	//����ջ�ṹ��������ʹ�õ�������
	stack *S;
	initStack(&S);
	//���Ҷ�Ϊ0�Ķ��㣬��Ϊ��ʼ��
	for (int i = 0; i < G.vexnum; i++) {
		if (!indegree[i]) {
			push(S, i);
		}
	}
	int count = 0;
	//��ջΪ�գ�˵���������
	while (!StackEmpty(*S)) {
		int index;
		//��ջ������¼ջ�б���Ķ��������ڽӱ������е�λ��
		pop(S, &index);
		printf("%d", G.vertices[index].data);
		++count;
		//���β��Ҹ��ö��������ӵĶ��㣬�����ʼ���Ϊ1����ɾ��ǰһ������󣬸ö������Ϊ0
		for (ArcNode *p = G.vertices[index].firstarc; p; p = p->nextarc) {
			VertexType k = p->adjvex;
			if (!(--indegree[k])) {
				//�������Ϊ0����ջ
				push(S, k);
			}
		}
	}
	//���countֵС�ڶ�������������������ͼ�л�
	if (count < G.vexnum) {
		printf("��ͼ�л�·");
		return;
	}
}
