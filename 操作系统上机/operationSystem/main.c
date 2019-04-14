/*
动态内存分配算法
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Lnode
{
    int startAddress;
    int size;
    bool state;
    bool lastChange;
    struct Lnode *prior,*next;
}LNode;

typedef struct item
{
    int num;
    int time;
}Pro;

LNode* Initial()  //初始化可用内存
{
    LNode *node0,* node1, *node2,*node3,*node4;

    node0 = (LNode*)malloc(sizeof(LNode));
    node1 = (LNode*)malloc(sizeof(LNode));
    node2 = (LNode*)malloc(sizeof(LNode));
    node3 = (LNode*)malloc(sizeof(LNode));
    node4 = (LNode*)malloc(sizeof(LNode));

    node0->startAddress = 0;
    node0->size = 256;
    node0->state = false;
    node0->lastChange = false;
    node0->prior = NULL;
    node0->next = node1;

    node1->startAddress = 300;
    node1->size = 128;
    node1->state = false;
    node1->lastChange =false;
    node1->prior = node0;
    node1->next = node2;

    node2->startAddress = 500;
    node2->size = 256;
    node2->state = false;
    node2->lastChange = false;
    node2->prior = node1;
    node2->next = node3;

    node3->startAddress = 800;
    node3->size = 300;
    node3->state = false;
    node3->lastChange = false;
    node3->prior = node2;
    node3->next = node4;

    node4->startAddress = 1200;
    node4->size = 512;
    node4->state = false;
    node4->lastChange = false;
    node4->prior = node3;
    node4->next = NULL;


    return node0;
}

void FirstMethod(LNode * node)
{
    int size;
    printf("Please input the size\n");
    scanf("%d",&size);
    while(node)
    {
        node->lastChange = false;
        if(node->size >= size && !(node->state))
        {
            node->state = true;
            node->lastChange = true;
            printf("Address allocate successful\n");
            while(node)
                node = node->prior;
            return;
        }
        node = node->next;
    }
    printf("Address allocate failed\n");
    while(node)
        node = node->prior;
    return;
}



void NextFit(LNode * node)
{
    int size;
    printf("Please input the size\n");
    scanf("%d",&size);
    while(node->lastChange == false)
    {
        node = node->next;
    }

    while(node)
    {
        node->lastChange = false;
        if(node->size >= size && !(node->state))
        {
            node->state = true;
            node->lastChange = true;
            printf("Address allocate successful\n");
            while(node)
                node = node->prior;
            return;
        }
        node = node->next;
    }
    printf("Address allocate failed\n");
    while(node)
        node = node->prior;
    return;

}

void Show(LNode * node)
{
    printf("State!!!!!!!!!!!!!!!!!!!!!!\n"
           "StartAddress   size   state\n");
    while(node)
    {
        printf("%12d%7d%8d\n",node->startAddress,node->size,node->state);

        node = node->next;
    }

    while(node)
        node = node->prior;
    return;
}

int main()
{
    printf("~~~~~~~~~~~~~Memory Methods~~~~~~~~~~~~~~\n");
    printf("1.First method\n2.Next fit method\n3.Exit\n");

    LNode * node = Initial();
    int choose = 0;

    Show(node);
    while (1) {
        printf("Please input the method!\n");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                FirstMethod(node);
                Show(node);
                break;
            case 2:
                NextFit(node);
                Show(node);
                break;
            case 3:
                printf("Process end\n");
                return  0;
                break;
            default:
                break;
        }
    }

    return 0;
}