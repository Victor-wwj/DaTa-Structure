#include<iostream>
#define Maxsize 5
typedef int Elemtype;

//顺序栈
typedef struct 
{
    Elemtype data[Maxsize];
    int top;        //栈顶指针
}SqStack;

//初始化栈
void InitStack(SqStack*&s){
    s=(SqStack*)malloc(sizeof(SqStack));
    s->top=-1;
}
//销毁栈
void DestryStack(SqStack*&s){
    free(s);
}
//判空
bool StackEmpty(SqStack*s){
    return(s->top==-1);
}
//进栈
bool Push(SqStack*&s,Elemtype e){
    if(s->top==Maxsize-1)return false;
    s->top++;
    s->data[s->top]=e;
    return true;
}
//出栈
bool Pop(SqStack*&s,Elemtype e){
    if(s->top==-1)return false;
    e=s->data[s->top];
    s->top--;
    return true;
}
//判断是否对称
//进栈顺序与出栈顺序是否一致
bool symmetry(Elemtype str[]){
    int i; Elemtype e;
    SqStack *st;
    InitStack(st);
    for(i=0;str[i]!='\0';i++)
        Push(st,str[i]);
    for ( i = 0;str[i]!='\0'; i++)
    {
        Pop(st,e);
        if(str[i]!=e){
            DestryStack(st);
            return false;
        }
    }
    DestryStack(st);
    return true;
}
