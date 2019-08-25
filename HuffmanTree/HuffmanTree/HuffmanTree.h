#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//哈夫曼树结点结构
typedef struct {
	int weight;//结点权重
	int parent, left, right;//父结点、左孩子、右孩子在数组中的位置下标
}HTNode, *HuffmanTree;
//动态二维数组，存储哈夫曼编码
typedef char ** HuffmanCode;
void Select(HuffmanTree HT, int end, int *s1, int *s2);
void CreateHuffmanTree(HuffmanTree *HT, int *w, int n);
void HuffmanCoding(HuffmanTree HT, HuffmanCode *HC, int n);
void PrintHuffmanCode(HuffmanCode htable, int *w, int n);
