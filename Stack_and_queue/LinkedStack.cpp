#include<iostream>
typedef char Elemtype;
typedef struct linkNode
{
    Elemtype data;
    struct linkNode * next;
}LinkStNode;

//初始化栈
void InitStack(LinkStNode*&L){
    L=(LinkStNode*)malloc(sizeof(LinkStNode));
    L->next=NULL;
}

//销毁栈
void DestoryStack(LinkStNode*&L){
    LinkStNode*pre=L,*p=L->next;
    while (p!=NULL)
    {
        free(pre);
        pre=p;
        p=p->next;
    }
    free(pre);
}

//判空
bool StackEmpty(LinkStNode*L){
    return(L->next==NULL);
}

//进栈
void Push(LinkStNode*&L,Elemtype e){
    LinkStNode*p;
    p=(LinkStNode*)malloc(sizeof(LinkStNode));
    p->data=e;
    p->next=L->next;
    L->next=p;
}

//出栈
bool Pop(LinkStNode*&L,Elemtype e){
    LinkStNode*p;
    if(L->next==NULL)return false;
    p=L->next;
    p->data=e;
    L->next=p->next;
    free(p);
    return true;
}

//取栈顶
bool GetTop(LinkStNode*p,Elemtype &e){
    if(p->next==NULL)return false;
    e=p->next->data;
    return true;
}

//判断字符串括号是否对称
bool Match(char str[],int n){           //字符串str，字符串长度n
   LinkStNode*p;
   int i=0;char e;
   bool match = true;
   InitStack(p);
    while (i<n&&match)
    {
        if(str[i]=='(')
            Push(p,str[i]);
        else if (str[i]==')')
        {
            bool result=GetTop(p,e);
            if(result==false)match=false;
            else
                if(e!='(')match=false;
                else Pop(p,e);
        }
        i++;
    }
    if(!StackEmpty(p))match==false;
    DestoryStack(p);
    return match;
}

//@test
int main(){
    char str[]="(cao)";
    int n=sizeof(str)-1;
    bool result=Match(str,n);
    if(result)
    printf("the str is match");
    else
    printf("the str is not match");
    return 0;
}