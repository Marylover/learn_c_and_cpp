/*
program2.c 作者：ICTbeginner
使用信号量解决一个生产者/消费者问题：建立一个线程可以从键盘连续输
入小写字母组成的字符，将得到的送人一个队列汇中；建立另一个线程从队列中依次读取字
符转化为相应的大写字符后在终端显示。
*/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include<string.h>

#define MAXSIZE 10

char stack[MAXSIZE]; //缓冲区
int size = 0;
sem_t sem;  //同步信号量
sem_t sem1; //互斥信号量
sem_t sem2;

// 生产者
void provide_data(void) {
    int i;
    char ch;
    while(1)
    {
    sem_wait(&sem2);
    i=0;
    size = 0;
    printf("生产者开始\n");
    while((ch = getchar()) != '\n')
    {
        if(ch>('a'-1)&&(ch<'z'+1))
        {
        stack[i++] = ch;
        size++;
        sem_post(&sem);
        }
        else
        {
            printf("请输入小写字母\n");
        }
         
    }
     
    printf("生产者结束\n");
    sem_post(&sem1);
    }

   
}

// 消费者
void handle_data(void) {
    while(1)
    {
    sem_wait(&sem1);
    printf("消费者开始\n");
    int i = 0;
    while(i  < size) {
        sem_wait(&sem);
        stack[i] = stack[i] -('a'-'A');
        printf("%c",stack[i]);
        i++;
    }
    printf("\n消费者结束\n");
    sem_post(&sem2);
    }
}

int main(void) {

    pthread_t provider, handler;

    sem_init(&sem, 0, 0); //信号量初始化
    sem_init(&sem1, 0,0); //信号量初始化
    sem_init(&sem2,0,1);
    pthread_create(&provider, NULL, (void *)handle_data, NULL);
    pthread_create(&handler, NULL, (void *)provide_data, NULL);
    pthread_join(provider, NULL);
    pthread_join(handler, NULL);
    sem_destroy(&sem); //销毁信号量
    sem_destroy(&sem1); //销毁信号量
    sem_destroy(&sem2);

    return 0;
}