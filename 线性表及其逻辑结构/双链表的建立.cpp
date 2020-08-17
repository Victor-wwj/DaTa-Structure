#include<iostream>
typedef char ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DlinkList;

//头插法建立双链表
void CreateListF(DlinkList*&L,ElemType a[],int n){
    DlinkList*s;int i;
    L=(DlinkList*)malloc(sizeof(DlinkList));    //创建头节点
    L->prior=L->next=NULL;      //前后指针域置为NULL
    for(i=0;i<n;i++){           //循环建立数据节点
        s=(DlinkList*)malloc(sizeof(DlinkList));
        s->data=a[i];           //创建数据节点*s
        s->next=L->next;        //将*s插入到头节点之后
        if(L->next!=NULL)       //若L存在，修改前趋指针
            L->next->prior=s;
        L->next=s;
        s->prior=L;
    }
}

//尾插法建表
void CreateListR(DlinkList*&L,ElemType a[],int n){
    DlinkList*s,*r;
    int i;
    L=(DlinkList*)malloc(sizeof(DlinkList));
    r=L;
    for(i=0;i<n;i++){
        s=(DlinkList*)malloc(sizeof(DlinkList));
        s->data=a[i];
        r->next=s;
        s->prior=r;
        r=s;
    }
    r->next=NULL;
}