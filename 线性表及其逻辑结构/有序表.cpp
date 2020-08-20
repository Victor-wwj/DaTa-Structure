//有序表就是线性表，只是把元素的大小呈递或递减
//有序表可能是顺序表可能是链表（逻辑->存储）
//基本算法中至于ListInsert有差异

#include<iostream>
typedef int ElemType;
//顺序表基本类型
    typedef struct 
    {
        ElemType data[100];
        int lenth;
    }Sqlist;

//单链表基本类型
    typedef struct LNode
    {
        ElemType data;
        struct LNode*next;
    }LinkList;

//顺序表的插入运算
void ListInsert1(Sqlist*&L,ElemType e){
    int i=0,j;
    while (i<L->lenth&&L->data[i]<e)
        ++i;
    for(j=L->lenth;j>i;j--)
        L->data[j]=L->data[j-1];
    L->data[i]=e;
    L->lenth++;
}

//单链表的插入运算
void ListInsert2(LinkList*&L,ElemType e){
    LinkList*pre=L,*p;
    while (pre->next!=NULL&&pre->next->data<e)
        pre=pre->next;
    p=(LinkList*)malloc(sizeof(LinkList));
    p->data=e;
    p->next=pre->next;
    pre->next=p;
}

//以顺序表的形式进行有序表的二路归并
//O(m+n)
void UninList(Sqlist*LA,Sqlist*LB,Sqlist*&LC){
    int i=0,j=0,k=0;
    LC=(Sqlist*)malloc(sizeof(Sqlist));
    while (i<LA->lenth&&j<LB->lenth)
    {
        if(LA->data[i]<LB->data[j]){
            LC->data[k]=LA->data[i];
            i++;k++;
        }
        else{
            LC->data[k]=LB->data[j];
            j++;k++;
        }
    }
    while (i<LA->lenth)
    {
        LC->data[k]=LA->data[i];
        i++;k++;
    }
    while (j<LB->lenth)
    {
        LC->data[k]=LB->data[j];
        j++;k++;
    }
    LC->lenth=k;
}

//以单链表的形式进行有序表的二路归并
//O(m+n)
void UnionList1(LinkList*LA,LinkList*LB,LinkList*&LC){
    LinkList*pa=LA->next;
    LinkList*pb=LB->next;
    LinkList*r,*s;
    LC=(LinkList*)malloc(sizeof(LinkList));
    r=LC;
    while (pa!=NULL&&pb!=NULL)
    {
        if(pa->data<pb->data){
            s=(LinkList*)malloc(sizeof(LinkList));
            s->data=pa->data;
            r->next=s;r=s;
            pa=pa->next;
        }
        else{
            s=(LinkList*)malloc(sizeof(LinkList));
            s->data=pb->data;
            r->next=s;r=s;
            pb=pb->next;
        }
    }
    while (pa!=NULL)
    {
        s=(LinkList*)malloc(sizeof(LinkList));
        s->data=pa->data;
        r->next=s;r=s;
        pa=pa->next;
    }
    while (pb!=NULL)
    {
        s=(LinkList*)malloc(sizeof(LinkList));
        s->data=pb->data;
        r->next=s;r=s;
        pb=pb->next;
    }
    r->next=NULL;
}

//归并找中位数
//时间复杂度O(n)，空间复杂度O(1)
//n为AB长度和的中位数
int M_Search(int A[],int B[],int n){
    int i,j,k;
    while (i<n&&j<n)
    {
        k++;
        if (A[i]<B[j])
        {
            if(k==n)return A[i];
            ++i;
        }
        else{
            if(k==n)return B[j];
            ++j;
        }
    }
}