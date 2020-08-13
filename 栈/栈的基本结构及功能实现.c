#include<stdio.h>
#define Stack_Size 50
#define TRUE 0
#define FALSE -1
typedef char StackElemtype;
typedef struct 
{
    StackElemtype elem[Stack_Size];
    int top;
}SeqStack;

//初始化
void InitStack(SeqStack*s){
    s->top=-1;
}

//判栈空
int IsEmpty(SeqStack*s){
    return(s->top==-1?TRUE:FALSE);
}

//判满栈
int IsFull(SeqStack*S){
    return(S->top==Stack_Size-1?TRUE:FALSE);
}

//进栈
int Push(SeqStack*s,StackElemtype x){
    if(s->top==Stack_Size-1)return FALSE;
    s->top++;
    s->elem[s->top]=x;
    return TRUE;
}

//出栈
int Pop(SeqStack*s,StackElemtype*x){
    if(s->top==-1)return FALSE;//栈为空
    else{
            *x=s->elem[s->top];
            s->top--;
            return TRUE;
    }
}

//取栈顶元素
char GetTop(SeqStack*s,StackElemtype*x){
    if(s->top==-1) return ("empty");
    else{
        *x=s->elem[s->top];
        return *x;
    }
}