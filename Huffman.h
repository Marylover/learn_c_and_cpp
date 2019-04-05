#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX_CODE_LENGTH 100      /*最大信源长度*/
#define MAX_HUFFMAN_CODE_LENGTH 10    /*最大哈夫曼码长*/

FILE *out;  
int codeNumber;
char str[MAX_CODE_LENGTH];

typedef char ElemType;

/*
存放每个信源符号出现次数的结构体
*/
typedef struct Mapset
{
	int times;  //出现次数
	ElemType data;  //信源符号
}Map;

/*
存放从信源到编码映射的结构体
没有用hash表
*/
typedef struct
{
	char code[MAX_HUFFMAN_CODE_LENGTH];  //已编码
	ElemType symbol;  //信源符号
}codeMap;
/*
哈夫曼树节点结构体
*/
typedef struct HuffmanTree
{
	int weight;  //权值，即在信源中符号出现次数
	ElemType data;  //符号
	struct  HuffmanTree * left;  //左孩子
	struct  HuffmanTree * right; //右孩子

}Huffman;

extern Huffman * CreateHuffmanTree(Map** mapset);
extern void HuffmanCoding(Huffman * huffman, int len, codeMap ** codemap);
extern Map** CreatMap();
extern void putCode(codeMap ** codemap);