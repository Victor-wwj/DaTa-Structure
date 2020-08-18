//没有空指针域
//p所指节点为尾结点的条件：p->next==L
//L->prior可以找到尾节点（双链表）

#include<iostream>
typedef char ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DlinkList;

//判断带头节点的循环双链表是否对称
bool IsEqual(DlinkList*L){
    DlinkList*p=L->next;
    DlinkList*q=L->prior;
    int same=1;
    while (p!=q)
    {
        if(p->data!=q->data)
            same=0;
            break;
        p=p->next;
        q=q->prior;
        if(p==q->prior)break;
    }
    if(same==1)return true;
    else return false;
}
