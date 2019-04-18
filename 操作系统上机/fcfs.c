#include<stdio.h>
#include<stdlib.h>
typedef struct process_FCFS{
char name ;  //进程名
float arrivetime;//到达时间
float servetime;//服务时间
float finishtime;//完成时间
float roundtime;//周转时间
float daiquantime;//带权周转时间
struct process_FCFS *link;//结构体指针
}FCFS;
FCFS *p,*q,*head=NULL;
struct process_FCFS a[100];
//按到达时间进行冒泡排序
struct process_FCFS *sortarrivetime(struct process_FCFS a[],int n)
{
int i,j;
struct process_FCFS t;
int flag;
for(i=1;i<n;i++)
{
flag=0;
for(j=0;j<n-i;j++)
{
if(a[j].arrivetime>a[j+1].arrivetime)
{
t=a[j];
a[j]=a[j+1];
a[j+1]=t;
flag=1;//交换
}
}
if(flag==0)//如果一趟排序中没发生任何交换，则排序结束
break;
}
return a;
}
//先来先服务算法
void print(FCFS * a,int n)
{
int i;
float all_roundtime = 0;
float all_daiquantime = 0;
for(i=0;i<n;i++)
{
all_daiquantime += a[i].daiquantime;
all_roundtime +=a[i].roundtime;
printf("进程名: %c",a[i].name);
printf("到达时间：%2.f",a[i].arrivetime);
printf("服务时间：%2.f",a[i].servetime);
printf("完成时间：%2.f",a[i].finishtime);
printf("周转时间：%2.f",a[i].roundtime);
printf("带权周转时间：%.2f",a[i].daiquantime);
printf("\n");
}
printf("平均周转时间为:%f",all_roundtime/n);
printf("平均带权周转时间为:%f",all_daiquantime/n);
}
void Fcfs(struct process_FCFS a[],int n)
{
int i;
a[0].finishtime=a[0].arrivetime+a[0].servetime;
a[0].roundtime=a[0].finishtime+a[0].arrivetime;
a[0].daiquantime=a[0].roundtime/a[0].servetime;
for(i=0;i<n;i++)
{
if(a[i].arrivetime<a[i-1].finishtime)
{
a[i].finishtime=a[i-1].finishtime+a[i].servetime;
a[i].roundtime=a[i].finishtime-a[i].arrivetime;
a[i].daiquantime=a[i].roundtime/a[i].servetime;
}
else
{
a[i].finishtime=a[i].arrivetime+a[i].servetime;
a[i].roundtime=a[i].finishtime-a[i].arrivetime;
a[i].daiquantime=a[i].roundtime/a[i].servetime;
}
}
printf("先来先服务\n");
print(a,n);
}
//主函数
int main()
{
int n,i;
printf("请输入有几个进程\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("进程名:");
setbuf(stdin,NULL);
scanf("%c",&a[i].name);
printf("到达时间:");
setbuf(stdin,NULL);
scanf("%f",&a[i].arrivetime);
printf("服务时间:");
setbuf(stdin,NULL);
scanf("%f",&a[i].servetime);
}
Fcfs(a,n);
getchar();

return 0;
}
