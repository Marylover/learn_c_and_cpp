#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX_CODE_LENGTH 100      /*�����Դ����*/
#define MAX_HUFFMAN_CODE_LENGTH 10    /*���������볤*/

FILE *out;  
int codeNumber;
char str[MAX_CODE_LENGTH];

typedef char ElemType;

/*
���ÿ����Դ���ų��ִ����Ľṹ��
*/
typedef struct Mapset
{
	int times;  //���ִ���
	ElemType data;  //��Դ����
}Map;

/*
��Ŵ���Դ������ӳ��Ľṹ��
û����hash��
*/
typedef struct
{
	char code[MAX_HUFFMAN_CODE_LENGTH];  //�ѱ���
	ElemType symbol;  //��Դ����
}codeMap;
/*
���������ڵ�ṹ��
*/
typedef struct HuffmanTree
{
	int weight;  //Ȩֵ��������Դ�з��ų��ִ���
	ElemType data;  //����
	struct  HuffmanTree * left;  //����
	struct  HuffmanTree * right; //�Һ���

}Huffman;

extern Huffman * CreateHuffmanTree(Map** mapset);
extern void HuffmanCoding(Huffman * huffman, int len, codeMap ** codemap);
extern Map** CreatMap();
extern void putCode(codeMap ** codemap);