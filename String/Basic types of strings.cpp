#include<iostream>
#define MaxSize 100
typedef struct
{
    char data[MaxSize];     //存储字符串
    int length;             //存储字符串长度
}SqString;

void StrAssign(SqString&s,char cstr[]){
    int i;
    for(i=0;cstr[i]!='\0';i++)
        s.data[i]=cstr[i];
    s.length++;
}

void StrCopy(SqString&s,SqString t){
    int i;
    for(i=0;i<t.length;i++)
        s.data[i]=t.data[i];
    s.length=t.length;
}

bool StrEqual(SqString s,SqString t){
    bool same=true;int i;
    if(s.length!=t.length)same=false;
    for(i=0;i<s.length;i++){
        if (s.data[i]!=t.data[i])
        {
            same=false;
            break;
        }
    }
    return same;
}

//基本算法类比线性表，这里不再举例了
//太无聊了！！！！！

typedef struct snode
{
    char data;
    struct snode*next;
}LiString;