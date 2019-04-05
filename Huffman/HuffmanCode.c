
#include"Huffman.h"

int main()
{
	Map ** map;
	map = CreatMap();
	codeMap ** codemap;
	codemap = (codeMap**)malloc(codeNumber*sizeof(codeMap));
	Huffman * huffman;
	huffman = CreateHuffmanTree(map);

	HuffmanCoding(huffman, 0,codemap);

	putCode(codemap);

	

	system("pause");
	return 0;
}