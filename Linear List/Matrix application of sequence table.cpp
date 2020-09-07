//矩阵相关设计
//行是节点个数，一列的数存储在一个节点的数据域里
//头节点存储行数、列数
//像单链表和顺序表的结合
#define MaxCol 10
#include <iostream>

typedef int Elemtype;

//数据节点类型
typedef struct Nodel
{
    Elemtype data[MaxCol];
    struct Nodel *next;
}Dlist;

//头节点类型
typedef struct Node2
{
    int Row,Col;
    Dlist *next;
}HList;

//交互式创建单链表
void CreateTable(HList*&h){
    int i,j;
    Dlist*r,*s;
    h=(HList*)malloc(sizeof(HList));
    h->next=NULL;
    printf("please enter the row and the col:");
    scanf("%d%d",&h->Row,&h->Col);
    for(i=0;i<h->Row;i++){
        printf("第%d行：",i+1);
        s=(Dlist*)malloc(sizeof(Dlist));
        for(j=0;j<h->Col;j++){
            scanf("%d",&s->data[j]);
        }
        if(h->next==NULL)
            h->next=s;
        else
            r->next=s;
        r=s;
    }
    r->next=NULL;
}

//输出单链表
void DispTables(HList*h){
    int j;
    Dlist*p=h->next;
    while (p!=NULL)
    {
        for(j=0;j<h->Col;++j)
            printf("%4d",p->data[j]);
        p=p->next;
    }  
}

//表连接算法
//连接条件举例：表一中的第一个节点的第三个数据与表二中每个节点第一个数据一样
void LinkTable(HList*h1,HList*&h2,HList*&h){
    int i,j,k;
    Dlist*p=h1->next,*q,*s,*r;
    printf("连接字段是：第1个表序号，第2个序号：");
    scanf("%d%d",&i,&j);
    h=(HList*)malloc(sizeof(HList));
    h->next=NULL;
    h->Row=0;
    h->Col=h1->Col + h2->Col;
    while (p!=NULL)
    {
        q=h2->next;
        while (q!=NULL)
        {
            //拼数据
            if (p->data[i-1]==q->data[j-1])
            {
                s=(Dlist*)malloc(sizeof(Dlist));
                for(k=0;k<h1->Col;++k)
                    s->data[k]=p->data[k];
                for(k=0;k<h2->Col;++k)
                    s->data[h1->Col+k]=q->data[k];
            //尾插建表
            if (h->next=NULL)
                h->next=s;
            else
                r->next=s;
            r=s;
            h->Row++;   //表的行数加1                    
            }
            q=q->next;  //表2移到下一行
        }
        p=p->next;  //表1一行与表2比较合并结束，移到下一行
    }
    r->next=NULL;   //新表建表结束，尾指针指向null
}

int main(){
    HList*h1,*h2,*h;
    printf("表1：\n");
    CreateTable(h1);
    printf("表2：\n");
    CreateTable(h2);
    LinkTable(h1,h2,h);
    printf("连接结果：\n");
    DispTables(h);
    return 0;
}