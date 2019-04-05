#define _CRT_SECURE_NO_WARNINGS
#include"Huffman.h"

/*
����:����һ�Ź�������
�����������ʾ�����ַ����ִ����Ľṹ��ָ��
����ֵ������Huffman���͵Ľṹ��ָ��
*/
Huffman * CreateHuffmanTree(Map** mapset)
{
	int n = codeNumber;
	int i, j;
	Huffman **b, *q = NULL; //b��ָ��ṹ��ָ���ָ�룬�൱��һ��Ԫ��ΪHuffanTree������
	b = (Huffman **)malloc(n * sizeof(Huffman));
	for (i = 0; i < n; i++)  //����n��ֻ�и��ڵ����
	{
		b[i] = (Huffman*)malloc(sizeof(Huffman));
		b[i]->weight = mapset[i]->times;
		b[i]->data = mapset[i]->data;
		b[i]->left = b[i]->right = NULL;
	}
	for (i = 1; i < n; i++) //��ʼ����Huffman��
	{
		int k1 = -1, k2; //k1ָ��Ȩֵ��С������k2ָ��Ȩֵ��С����
		for (j = 0; j < n; j++)
		{
			if (b[j] != NULL && k1 == -1)
			{
				k1 = j; //��һ��ѭ�����ѵ�һ���ǿյ�������Ȩֵ��С����
				continue; //��������ѭ��
			}
			if (b[j] != NULL)
			{
				k2 = j; break; //�ѵڶ����ǿ�������Ȩֵ��С���������������forѭ��
			}
		}
		for (j = k2; j < n; j++) //��ð���������ƣ�������ɭ��Ѱ���������С
		{
			if (b[j] != NULL)
			{
				if (b[j]->weight < b[k1]->weight) //��ǰ��Ȩֵ����С��Сʱ
				{
					k2 = k1; //������С������ԭ��С��Ϊ��С
					k1 = j;
				}
				else if (b[j]->weight < b[k2]->weight)
				{
					k2 = j;  //��ֻ�Ǳȴ�С��С��ֻ���´�С
				}
			}
		}

		q = (Huffman*)malloc(sizeof(Huffman)); //��Ȩֵ��С���������ϲ�
		q->weight = b[k1]->weight + b[k2]->weight;//������ȨֵΪ����Ȩֵ֮��
		q->left = b[k1];//���������Һ��ӷֱ�Ϊ����Ȩֵ��С����
		q->right = b[k2];

		b[k1] = q;  //����������ԭ���У���������ΪȨ��С����
		b[k2] = NULL;
	}

	free(b);
	return q;
}
/*
���ܣ����ɹ������������������һ���뱾(codeMap�Ķ��ؽṹ��ָ��)��
���������һ��Huffman���ͽṹ��ָ��
		һ����ʼ��Ϊ0��int����
		һ�������뱾��codeMap����ָ��
*/
void HuffmanCoding(Huffman * huffman, int len, codeMap ** codemap)
{
	static int a[MAX_HUFFMAN_CODE_LENGTH];
	if (huffman != NULL);
	{
		int i = 0;
		static int j = 0;
		if (huffman->left == NULL && huffman->right == NULL)
		{ //��û�к���ʱ������Դ���ڽڵ㣬��ʼ�������
			codeMap * codemap1 = (codeMap*)malloc(sizeof(codeMap));  //����һ���µ���Դ�������ӳ��
			printf("����%c��huffman����Ϊ��", huffman->data); 
			codemap1->symbol = huffman->data;  
			for (i = 0; i < len; i++)
			{
				printf("%d", a[i]);
				codemap1->code[i] = (a[i] + '0');  //�������ֵ�ӳ���ϵ
			}
			putchar('\n');
			codemap1->code[i] = '\0';
			codemap[j] = codemap1;    //�������ɵ�ӳ�䱣�浽�뱾
			j++;
		}
		else  //��0��1�����ϵ���
		{
			a[len] = 0;
			HuffmanCoding(huffman->left, len + 1, codemap);
			a[len] = 1;
			HuffmanCoding(huffman->right, len + 1, codemap);
		}
	}
}
/*
���ܣ��Ӽ��̻��ļ��ж�ȡ�ַ���ͳ��ÿ���ַ����ָ��ʣ���Դ���ſ�����ASCII���0~256
�����������
����ֵ��Map���Ͷ���ָ��
*/
Map** CreatMap()
{
	Map **mapset = NULL;
	int choose = -1;
	codeNumber = 0;
	int i, num[256] = { 0 };
	printf("���� 1 ���Ӽ��̶�ȡ��Դ\n����2�� ���ļ���ȡ��Դ\n");
	scanf("%d", &choose);
	if (choose == 1)       //�Ӽ���������Դ
	{
		printf("please input string:\n");
		scanf("%s", str);
		for (i = 0; i < strlen(str); i++)
			num[(int)str[i]]++;           //ͳ�Ƹ�����Դ���ų��ִ���
		for (i = 0; i < 256; i++)  
		{
			if (num[i] != 0)
			{
				codeNumber++;             //ͳ�ƹ��ж��ٸ���ͬ����Դ����
			}
		}
		mapset = (Map**)malloc(codeNumber * sizeof(Map));   //����ͳ����Դ���ִ������뱾
		codeNumber = 0;
		for (i = 0; i < 256; i++)
		{
			if (num[i] != 0)
			{
				mapset[codeNumber] = (Map*)malloc(sizeof(Map));  //����һ���µ���Դ��������ִ�����ӳ��
				mapset[codeNumber]->data = (char)i;   //�����������뱾
				mapset[codeNumber]->times = num[i];
				codeNumber++;
			}
		}
	}
	if (choose == 2)   //���ļ���ȡ��Դ
	{
		printf("�������ڴ�Ŀ¼�µ�һ���ļ���\n");
		char name[10];
		scanf("%s", name);
		FILE * fp;
		if ((fp = fopen(name, "r")) == NULL)
		{
			printf("���ļ�%sʧ�ܣ������ļ��Ƿ���ڣ������������ļ���\n", name);
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
���ܣ��������������
������������ɵĹ������뱾
*/
void putCode(codeMap ** codemap) 
{
	out = fopen("out.txt", "a");
	printf("%s�Ĺ������������£��ÿո��ʾ������\n", str);
	fprintf(out,"%s�Ĺ������������£��ÿո��ʾ������\n", str);
	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = 0; j < codeNumber; j++)
		{
			if (str[i] == codemap[j]->symbol)    //������б������ҵ���ǰ�ַ��Ĺ���������
			{
				printf("%s ", codemap[j]->code);
				fprintf(out,"%s ", codemap[j]->code);  //��������浽�ļ�
			}
		}

	}
	fprintf(out, "\n");
	fclose(out);
}