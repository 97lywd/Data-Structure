#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define  MAX_VERTEX_NUM 20//��󶥵����
typedef int VertexType;
typedef enum { false, true } bool;
typedef struct ArcNode {
	int adjvex;//�ڽӵ��������е�λ���±�
	struct ArcNode * nextarc;//ָ����һ���ڽӵ��ָ��
}ArcNode;

typedef struct VNode {
	VertexType data;//�����������
	ArcNode * firstarc;//ָ���ڽӵ��ָ��
}VNode, AdjList[MAX_VERTEX_NUM];//�洢������ͷ��������

typedef struct {
	AdjList vertices;//ͼ�ж��㼰���ڽӵ�����
	int vexnum, arcnum;//��¼ͼ�ж������ͱ߻���
}ALGraph;

//�ṹ�嶨��ջ�ṹ
typedef struct stack {
	VertexType data;
	struct stack * next;
}stack;



int LocateVex(ALGraph G, VertexType u);
void CreateAOV(ALGraph **G);
void initStack(stack* *S);
void push(stack *S, VertexType u);
void pop(stack *S, VertexType *i);
void FindInDegree(ALGraph G, int indegree[]);
void TopologicalSort(ALGraph G);

