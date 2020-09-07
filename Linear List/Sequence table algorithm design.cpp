
#include<iostream>
typedef char ElemType;

//顺序表基本类型
    typedef struct 
    {
        ElemType data[100];
        int lenth;
    }Sqlist;

//时间复杂度为O(n),空间复杂度为O(1)的删除算法
    void delnodel(Sqlist*&L,ElemType x){
        int k=0,i;
        for(i=0;i<L->lenth;i++)
            if(L->data[i]!=x){
                L->data[k]=L->data[i];
                k++;
            }
        L->lenth=k;
    }

    void delnode2(Sqlist*&L,ElemType x){
        int k=0,i=0;
        while (i<L->lenth)
        {
            if(L->data[i]==x)
                k++;
            else
                L->data[i-k]=L->data[i];
            i++;
        }
        L->lenth-=k;
        
    }

    //以data[0]为基准的分类算法，小于等于放其左，大于放其右
    void move1(Sqlist*&L){
        int i=0,j=L->lenth-1;
        ElemType pivot=L->data[0];
        while (i<j){
            while(j>i&&L->data[j]>pivot)
                j--;
            L->data[i]=L->data[j];
            while(i<j&&L->data[i]<=pivot)
                i++;
            L->data[j]=L->data[i];
        }
        L->data[i]=pivot;
    }

    void move2(Sqlist*&L){
        int i=0,j=L->lenth-1;
        ElemType tmp;
        ElemType pivot=L->data[0];
        while (i<j)
        {
            while(i<j&&L->data[j]>pivot)
                j--;
            while(i<j&&L->data[i]<=pivot)
                i++;
            if(i<j){
                tmp=L->data[i];
                L->data[i]=L->data[j];
                L->data[j]=tmp;
            }
        }
        tmp=L->data[0];
        L->data[0]=L->data[j];
        L->data[j]=tmp;
        
    }
    //就地算法应用应该善用数组下标逻辑关系和自定义计数器