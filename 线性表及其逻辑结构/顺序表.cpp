#include<iostream>
#define MaxSize 100;
 typedef char ElemType;

//顺序表基本类型
    typedef struct 
    {
        ElemType data[MaxSize];
        int lenth;
    }Sqlist;

 //main函数   
int mian(){

 //函数声明整体功能预览
    void CreateList(Sqlist*&L,ElemType a[],int n);
    void InitList(Sqlist*&L);
    void DestroyList(Sqlist*&L);
    bool ListEmpty(Sqlist*L);
    int ListLenth(Sqlist*L);
    void DisplayList(Sqlist*L);
    bool GetElem(Sqlist*L,int i,ElemType &e);
    int LocateElem(Sqlist*L,ElemType e);
    bool ListInsert(Sqlist*&L,int i,ElemType e);
    bool ListDelete(Sqlist*&L,int i,ElemType e)
}

//顺序表整体创建
    void CreateList(Sqlist*&L,ElemType a[],int n){
        int i;
        L=(Sqlist*)malloc(sizeof(Sqlist));
        for(i=0;i<n;i++)
            L->data[i]=a[i];
        L->lenth=n;    
    }

//创建顺序表
    void InitList(Sqlist*&L){
        L=(Sqlist*)malloc(sizeof(Sqlist));
        L->lenth=0;
    }

//销毁顺序表
    void DestroyList(Sqlist*&L){
        free(L);
    }

//判断是否为空顺序表
    bool ListEmpty(Sqlist*L){
        return(L->lenth==0);
    }

//返回顺序表长度
    int ListLenth(Sqlist*L){
        return(L->lenth);
    }

//输出顺序表
    void DisplayList(Sqlist*L){
        int i;
        if(ListEmpty(L))return;
        for(i=0;i<L->lenth;i++)
            printf("%c",L->data[i]);
        printf("\n");
    }

//求顺序表中某元素i的值并存放在变量e中
    bool GetElem(Sqlist*L,int i,ElemType &e){
       if(i<1||i>L->lenth) return false;
       e=L->data[i-1];
       return true;
    }

//查到顺序表中第一个与e值相等的元素返回序号
    int LocateElem(Sqlist*L,ElemType e){
        int i=0;
        while (i<L->lenth&&L->data[i]!=e)
            i++;  
        if (i<=L->lenth)return 0;
        else return i+1;
    }

//在顺序表第i个位置插入元素e
    bool ListInsert(Sqlist*&L,int i,ElemType e){
        int j;
        if(i<1||i>L->lenth+1)return false;
        i--;
        for(j=L->lenth;j>i;j--)
            L->data[j]=L->data[j-1];
        L->data[i]=e;
        L->lenth++;
        return true;
    }

//在顺序表第i个位置删除元素
    bool ListDelete(Sqlist*&L,int i,ElemType e){
        int j;
        if(i<1||i>L->lenth)return false;
        i--;
        e=L->data[i];
        for(j=i;j<L->lenth-1;j++)
            L->data[j]=L->data[j+1];
        L->lenth--;
        return true;
    }