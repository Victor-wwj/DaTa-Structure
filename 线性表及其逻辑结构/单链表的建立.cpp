#include<iostream>
typedef char ElemType;

//顺序表基本类型
    typedef struct LNode
    {
        ElemType data;
        struct LNode*next;
    }LinkList;

//头插法建表
void CreateList(LinkList*&L,ElemType a[],int n){
    LinkList*s;
    int i;
    L=(LinkList*)malloc(sizeof(LinkList));
    L->next=NULL; //创建头节点，其next域设为NULL
    for(i=0;i<n;i++){
        s=(LinkList*)malloc(sizeof(LinkList));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
    }
}
//尾插法建表
void CreatelistR(LinkList*&L,ElemType a[],int n){
    LinkList*s,*r;
    int i;
    L=(LinkList*)malloc(sizeof(LinkList));
    r=L; //r始终指向尾结点，开始时指向头结点
    for(i=0;i<n;i++){
        s=(LinkList*)malloc(sizeof(LinkList));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
}