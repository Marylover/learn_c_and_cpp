#define _CRT_SECURE_NO_WARNINGS
#include"Huffman.h"

/*
功能:创建一颗哈夫曼树
输入参数：表示各个字符出现次数的结构体指针
返回值：返回Huffman类型的结构体指针
*/
Huffman * CreateHuffmanTree(Map** mapset)
{
	int n = codeNumber;
	int i, j;
	Huffman **b, *q = NULL; //b是指向结构体指针的指针，相当于一个元素为HuffanTree的数组
	b = (Huffman **)malloc(n * sizeof(Huffman));
	for (i = 0; i < n; i++)  //创建n个只有根节点的树
	{
		b[i] = (Huffman*)malloc(sizeof(Huffman));
		b[i]->weight = mapset[i]->times;
		b[i]->data = mapset[i]->data;
		b[i]->left = b[i]->right = NULL;
	}
	for (i = 1; i < n; i++) //开始创建Huffman树
	{
		int k1 = -1, k2; //k1指向权值最小的树，k2指向权值次小的树
		for (j = 0; j < n; j++)
		{
			if (b[j] != NULL && k1 == -1)
			{
				k1 = j; //第一次循环，把第一个非空的树当作权值最小的树
				continue; //结束本次循环
			}
			if (b[j] != NULL)
			{
				k2 = j; break; //把第二个非空树当做权值次小的树，并跳出这个for循环
			}
		}
		for (j = k2; j < n; j++) //与冒泡排序类似，在整个森林寻找最下与次小
		{
			if (b[j] != NULL)
			{
				if (b[j]->weight < b[k1]->weight) //当前树权值比最小还小时
				{
					k2 = k1; //更新最小，并把原最小改为次小
					k1 = j;
				}
				else if (b[j]->weight < b[k2]->weight)
				{
					k2 = j;  //若只是比次小还小，只更新次小
				}
			}
		}

		q = (Huffman*)malloc(sizeof(Huffman)); //把权值最小的两个树合并
		q->weight = b[k1]->weight + b[k2]->weight;//新树的权值为两树权值之和
		q->left = b[k1];//新树的左右孩子分别为两个权值最小的树
		q->right = b[k2];

		b[k1] = q;  //把新树加在原树中，并把它置为权最小的树
		b[k2] = NULL;
	}

	free(b);
	return q;
}
/*
功能：生成哈夫曼码表，并把它存在一个码本(codeMap的二重结构体指针)中
传入参数：一个Huffman类型结构题指针
		一个初始化为0的int变量
		一个保存码本的codeMap二重指针
*/
void HuffmanCoding(Huffman * huffman, int len, codeMap ** codemap)
{
	static int a[MAX_HUFFMAN_CODE_LENGTH];
	if (huffman != NULL);
	{
		int i = 0;
		static int j = 0;
		if (huffman->left == NULL && huffman->right == NULL)
		{ //即没有孩子时，是信源所在节点，开始输出编码
			codeMap * codemap1 = (codeMap*)malloc(sizeof(codeMap));  //创建一个新的信源到编码的映射
			printf("符号%c的huffman编码为：", huffman->data); 
			codemap1->symbol = huffman->data;  
			for (i = 0; i < len; i++)
			{
				printf("%d", a[i]);
				codemap1->code[i] = (a[i] + '0');  //保存码字到映射关系
			}
			putchar('\n');
			codemap1->code[i] = '\0';
			codemap[j] = codemap1;    //把新生成的映射保存到码本
			j++;
		}
		else  //左0右1，从上到下
		{
			a[len] = 0;
			HuffmanCoding(huffman->left, len + 1, codemap);
			a[len] = 1;
			HuffmanCoding(huffman->right, len + 1, codemap);
		}
	}
}
/*
功能：从键盘或文件中读取字符，统计每个字符出现概率，信源符号可以是ASCII码表0~256
传入参数：无
返回值：Map类型二重指针
*/
Map** CreatMap()
{
	Map **mapset = NULL;
	int choose = -1;
	codeNumber = 0;
	int i, num[256] = { 0 };
	printf("输入 1 ，从键盘读取信源\n输入2， 从文件读取信源\n");
	scanf("%d", &choose);
	if (choose == 1)       //从键盘输入信源
	{
		printf("please input string:\n");
		scanf("%s", str);
		for (i = 0; i < strlen(str); i++)
			num[(int)str[i]]++;           //统计各个信源符号出现次数
		for (i = 0; i < 256; i++)  
		{
			if (num[i] != 0)
			{
				codeNumber++;             //统计共有多少个不同的信源符号
			}
		}
		mapset = (Map**)malloc(codeNumber * sizeof(Map));   //创建统计信源出现次数的码本
		codeNumber = 0;
		for (i = 0; i < 256; i++)
		{
			if (num[i] != 0)
			{
				mapset[codeNumber] = (Map*)malloc(sizeof(Map));  //创建一个新的信源符号与出现次数的映射
				mapset[codeNumber]->data = (char)i;   //并把它加入码本
				mapset[codeNumber]->times = num[i];
				codeNumber++;
			}
		}
	}
	if (choose == 2)   //从文件读取信源
	{
		printf("请输入在此目录下的一个文件名\n");
		char name[10];
		scanf("%s", name);
		FILE * fp;
		if ((fp = fopen(name, "r")) == NULL)
		{
			printf("打开文件%s失败，请检查文件是否存在，并重新输入文件名\n", name);
			scanf("%s", name);
		}
		else
		{
			fscanf(fp, "%s", str);
			for (i = 0; i < strlen(str); i++)
				num[(int)str[i]]++;
			for (i = 0; i < 256; i++)
			{
				if (num[i] != 0)
				{
					codeNumber++;
				}
			}
			mapset = (Map**)malloc(codeNumber * sizeof(Map));
			codeNumber = 0;
			for (i = 0; i < 256; i++)
			{
				if (num[i] != 0)
				{
					mapset[codeNumber] = (Map*)malloc(sizeof(Map));
					mapset[codeNumber]->data = (char)i;
					mapset[codeNumber]->times = num[i];
					codeNumber++;
				}
			}
			fclose(fp);
		}

	}
	return mapset;
}

/*
功能：输出哈夫曼编码
传入参数：生成的哈夫曼码本
*/
void putCode(codeMap ** codemap) 
{
	out = fopen("out.txt", "a");
	printf("%s的哈夫曼编码如下，用空格表示编码间隔\n", str);
	fprintf(out,"%s的哈夫曼编码如下，用空格表示编码间隔\n", str);
	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = 0; j < codeNumber; j++)
		{
			if (str[i] == codemap[j]->symbol)    //在码表中遍历，找到当前字符的哈夫曼编码
			{
				printf("%s ", codemap[j]->code);
				fprintf(out,"%s ", codemap[j]->code);  //把输出保存到文件
			}
		}

	}
	fprintf(out, "\n");
	fclose(out);
}