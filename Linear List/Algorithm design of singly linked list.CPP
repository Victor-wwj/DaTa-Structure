#include<iostream>
typedef char ElemType;

//顺序表基本类型
    typedef struct LNode
    {
        ElemType data;
        struct LNode*next;
    }LinkList;

//删除单链表中最大节点（假设唯一）
void DelMaxLone(LinkList*&L){
    LinkList*p=L->next,*pre=L; //负责遍历链表
    LinkList*maxp=p,*maxpre=pre; //负责比较
    while(p!=NULL){
        if(maxp->data < p->data){
            maxp=p;
            maxpre=pre;
        }
        pre=p;
        p=p->next;
    }
    maxpre->next=maxp->next;
    free(maxp);
}

//排序
void sort(LinkList*&L){
    LinkList*p,*pre,*q;
    p=L->next->next; //p指向L的第2个数据节点
    L->next->next=NULL; //构造只含一个数据节点的有序链表
    while (p!=NULL)
    {
        q=p->next;
        pre=L;
        while (pre->next!=NULL&&pre->next->data < p->data)
        {
            pre=pre->next;
        }
        p->next=pre->next;
        pre->next=p;
        p=q;
    }    
}