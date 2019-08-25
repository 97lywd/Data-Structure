#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define  MAX_VERTEX_NUM 20//��󶥵����
#define  VertexType int//�������ݵ�����
typedef enum { false, true } bool;
//����ȫ�ֱ���������ߵ����翪ʼʱ��
VertexType ve[MAX_VERTEX_NUM];
//����ȫ�ֱ���������ߵ�����ʼʱ��
VertexType vl[MAX_VERTEX_NUM];
typedef struct ArcNode {
	int adjvex;//�ڽӵ��������е�λ���±�
	struct ArcNode * nextarc;//ָ����һ���ڽӵ��ָ��
	VertexType dut;
}ArcNode;

typedef struct VNode {
	VertexType data;//�����������
	ArcNode * firstarc;//ָ���ڽӵ��ָ��
}VNode, AdjList[MAX_VERTEX_NUM];//�洢������ͷ��������

typedef struct {
	AdjList vertices;//ͼ�ж��㼰���ڽӵ�����
	int vexnum, arcnum;//��¼ͼ�ж������ͱ߻���
}ALGraph;
typedef struct stack {
	VertexType data;
	struct stack * next;
}stack;
stack *T;
int LocateVex(ALGraph G, VertexType u);
void CreateAOE(ALGraph **G);
void initStack(stack* *S);
void push(stack *S, VertexType u);
void pop(stack *S, VertexType *i);
void FindInDegree(ALGraph G, int indegree[]);
bool TopologicalOrder(ALGraph G);
void CriticalPath(ALGraph G);

