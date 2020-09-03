#include<iostream>
typedef char Elemtype;

//链队节点类型
typedef struct qnode
{
    Elemtype data;
    struct qnode * next;
}DataNode;

//链队头节点类型
typedef struct
{
    DataNode *front;    //队首节点
    DataNode *rear;     //队尾节点
}LinkQuNode;

//初始化
void  InitQueue(LinkQuNode*&L){
    L=(LinkQuNode*)malloc(sizeof(LinkQuNode));
    L->front=L->rear=NULL;
}

//销毁
void DestoryQueue(LinkQuNode*&L){
    DataNode *pre=L->front;     //pre指向队头
    DataNode *p;
    if (pre!=NULL)
    {
        p=pre->next;
        while (p!=NULL)
        {
            free(pre);
            pre=p;
            p=p->next;
        }
        free(pre);
    }
    free(L);
}

//判空
bool QueueEmpty(LinkQuNode*L){
    return(L->front==L->rear==NULL);
}

//进队
void enQueue(LinkQuNode*&L,Elemtype e){
    DataNode*p;
    p=(DataNode*)malloc(sizeof(DataNode));      //创建数据节点
    p->data=e;
    p->next=NULL;
    if(L->rear==NULL)
        L->front=L->rear=p;
    L->rear->next=p;        //尾插
    L->rear=p;
}

//出队
bool deQueue(LinkQuNode*&L,Elemtype &e){
    DataNode*p;
    if(L->rear==NULL)return false;      //队空
    p=L->front;     //p指向队头
    if(L->rear==L->front)       //只有一个节点，直接放掉
        L->front=L->rear=NULL;
    L->front=L->front->next;
    e-p->data;      //获取数据
    free(p);        //释放节点
    return true;
}