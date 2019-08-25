#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//�����������ṹ
typedef struct {
	int weight;//���Ȩ��
	int parent, left, right;//����㡢���ӡ��Һ����������е�λ���±�
}HTNode, *HuffmanTree;
//��̬��ά���飬�洢����������
typedef char ** HuffmanCode;
void Select(HuffmanTree HT, int end, int *s1, int *s2);
void CreateHuffmanTree(HuffmanTree *HT, int *w, int n);
void HuffmanCoding(HuffmanTree HT, HuffmanCode *HC, int n);
void PrintHuffmanCode(HuffmanCode htable, int *w, int n);
