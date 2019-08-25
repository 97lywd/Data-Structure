#include"HuffmanTree.h"
int main(void)
{
	int w[8] = { 5, 29, 7, 8,14,23,3,11 };
	int n = 8;
	HuffmanTree htree;
	HuffmanCode htable;
	CreateHuffmanTree(&htree, w, n);
	HuffmanCoding(htree, &htable, n);
	PrintHuffmanCode(htable, w, n);
	system("pause");								
	return 0;
}