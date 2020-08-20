#include<iostream>
typedef char ElemType;

//单链表基本类型
    typedef struct LNode
    {
        ElemType data;
        struct LNode*next;
    }LinkList;

//初始化线性表
void InitList(LinkList*&L){
    L=(LinkList*)malloc(sizeof(LinkList));
    L->next=NULL; //创建头节点指空
}

//销毁线性表
void DestoryList(LinkList*&L){
    LinkList*pre=L;
    LinkList*p=L->next; //pre指向头节点，p指向头节点的后趋节点
    while(p!=NULL){
        free(pre); //释放前趋节点
        pre=p;     //pre，p同步后移
        p=pre->next;
    }
    free(pre);    //释放最后一个节点
}

//判断是否为空表
bool ListEmpty(LinkList*L){
    return(L->next==NULL);
}

//求线性表的长度
int ListLenth(LinkList*L){
    int n=0;      //节点序号为0
    LinkList*p=L;  //p指向头节点
    while (p->next!=NULL)
    {
        n++;
        p=p->next;
    }
    return n;
}

//输出线性表
void DispList(LinkList*L){
    LinkList*p=L->next;
    while (p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}

//求线性表中位置i的数据元素
bool GetElem(LinkList*L,int i,ElemType &e){
    int j=0;
    LinkList*p=L;
    while (j<i&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)return false;
    else
    e=p->data;
    return true;
}

//查找与e值相同的节点返回位置
int LocateElem(LinkList*L,ElemType e){
    int i=1;
    LinkList*p=L->next;
    while(p!=NULL){
        if(e==p->data)return i;
        else{
            i++;
            p=p->next;
        }
    }
    if(p==NULL)return 0; //时间复杂度O(n)不具随机存储特性
}

//在第i个位置插入元素e
bool ListInsert(LinkList*&L,ElemType e,int i){
    int j=0;
    LinkList*p=L;
    LinkList*s;
    while (j<i-1&&p!=NULL)
    {
        j++;
        p=p->next; //找到i-1个节点，用p指向它
    }
    if(p==NULL)return false;
    else
    {
        s=(LinkList*)malloc(sizeof(LinkList));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return true;
    }
}

//删除第i个节点返回删除节点的data
bool ListDelete(LinkList*&L,int i,ElemType &e){
    int j=0;
    LinkList*p=L,*q;
     while (j<i-1&&p!=NULL)
    {
        j++;
        p=p->next; //找到i-1个节点，用p指向它
    }
    if(p==NULL)return false;
    else
    {
        q=p->next;
        if(q==NULL)return false;
        e=q->data;
        p->next=q->next;
        free(q);
        return true;
    }   
}