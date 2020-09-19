#include<iostream>
#include<string.h>
#define MaxSize 10
typedef struct
{
    char data[MaxSize];     //存储字符串
    int length;             //存储字符串长度
}SqString;


/*BF算法：
令i指向原串儿，j指向子串儿
开始匹配
不同则让 i = i-j+1 （回退），j = 0（从头开始）
j 超界，匹配成功，返回 i-t.length
O(mxn)
*/

int index(SqString s,SqString t){
    int i=0,j=0;
    while (i<s.length&&j<t.length)
    {
        if (s.data[i]==t.data[i])
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+1;
            j=0;
        }
    }
    if(j>=t.length)return(i-t.length);
    return -1;
}

/*KMP算法
next[j]是指t[j]字符前有多少个字符与t开头的字符相同
next[j]=k表示t[j]前有k个字符已经匹配成功，下一趟应从t[k]开始匹配
*/

void GetNext(SqString t,int next[]){
    int i,j,k;
    j=0;k=-1;next[0]=-1;
    while (j<t.length)
    {
        if (k==-1||t.data[j]==t.data[k])
        {
            j++;k++;
            next[j]=k;
        }
        else k=next[k];
    } 
}

int KMPIndex(SqString s,SqString t){
    int next[MaxSize],i=0,j=0;
    GetNext(t,next);
    while (i<s.length&&j<t.length)
    {
        if (j==-1||s.data[i]==t.data[j])
        {
            i++;
            j++;
        }
        else j=next[j];
    }
}

int main(int argc, char const *argv[])
{
    SqString s,t;
    strcpy(s.data,"abcdabb");
    strcpy(t.data,"aaabc");
    index(s,t);
    KMPIndex(s,t);
    return 0;
}
