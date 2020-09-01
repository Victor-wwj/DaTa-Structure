#include<iostream>
typedef char Elemtype;
#define Maxsize 5
//顺序队
typedef struct 
{
    Elemtype data[Maxsize];
    int front,rear;
}SqQueue;
/*约定
rear 队尾元素，元素进队，rear增1
front 指向当前队中队头元素的前一位置，元素出队，front增1
rear = Maxsize -1 时不能再进队
*/

//初始化
void InintQueue(SqQueue*&L){
    L=(SqQueue*)malloc(sizeof(SqQueue));
    L->front=L->rear=-1;
}

//销毁队列
void DEstoryQueue(SqQueue*&L){
    free(L);
}

//进队列
bool enQueue(SqQueue*&L,Elemtype e){
    if(L->rear==Maxsize-1)return false; //队满
    L->rear++;
    L->data[L->rear]=e;
    return true;
}

//出队列
bool deQueue(SqQueue*&L,Elemtype &e){
    if(L->front==L->rear)return false;  //队空
    L->front++;
    e=L->data[L->front];
    return true;
}

/*假溢出
前面满了，后面有空位
rear==Maxsize - 1 but front！= -1
设计环形队列或循环队列解决
*/
/*约定
队空：front=rear
队满：(rear+1)%Maxsize=front
进队：rear=(rear+1)%Maxsize  将e放在rear处
出队：front=(front+1)%Maxsize  取出front处元素e
*/
typedef struct
{
    Elemtype data[Maxsize];
    int front;
    int count;  //元素个数，利用元素个数省略队尾指针
}QuType;
/*
已知front、rear，求队列中元素个数count：
count=(rear-front+Maxsize)%Maxsize
已知front、count，求rear：
rear=(front+count)%Maxsize
已知rear、count,求front：
front=(rear-count+Maxsize)%Maxsize
*/


//初始化
void InitQueue(QuType*&qu){
    qu=(QuType*)malloc(sizeof(QuType));
    qu->front=0;
    qu->count=0;
}

//进队
bool EnQueue(QuType*&qu,Elemtype x){
    int rear;   //临时队尾指针
    if(qu->count==Maxsize)return false;
    rear=(qu->front+qu->count)%Maxsize;
    rear=(rear+1)%Maxsize;
    qu->data[rear]=x;
    qu->count++;
    return true;
}

//出队
bool DeQueue(QuType*&qu,Elemtype &x){
    if(qu->count==0)return false;
    qu->front=(qu->front+1)%Maxsize;
    x=qu->data[qu->front];
    qu->count--;
    return true;
}