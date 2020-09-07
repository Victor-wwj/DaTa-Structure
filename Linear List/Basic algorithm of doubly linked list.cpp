#include<iostream>
typedef char ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DlinkList;

//双链表的插入算法
bool ListInsert(DlinkList*&L,int i,ElemType e){
    int j=0;
    DlinkList*p=L,*s;
    while (j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)return false;
    else{
        s=(DlinkList*)malloc(sizeof(DlinkList));
        s->data=e;
        s->next=p->next;
        if(p->next!=NULL)
            p->next->prior=s;
        s->prior=p;
        p->next=s;
        return true;
    }    
}

//双链表的删除算法
bool ListDelete(DlinkList*&L,int i,ElemType e){
    int j=0;
    DlinkList*p=L,*q;
    while (j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)return false;
    else
    {
        q=p->next;
        if(q==NULL)return false;
        q->data=e;
        if(p->next!=NULL)
            p->next->prior=p;
        p->next=q->next;
        free(q);
        return true;
    }
}

//倒置
void RemoveList(DlinkList*&L){
    DlinkList*p=L->next,*q;  
    L->next=NULL;
    while (p!=NULL)
    {   q=p->next;
        p->next=L->next;
        if(L->next!=NULL)
            L->next->prior=p;
        L->next=p;
        p->prior=L;
        p=q;
    }  
}