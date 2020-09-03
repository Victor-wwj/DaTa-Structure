#include<iostream>
#define MaxSize 100
//8x8迷宫
int static mg[10][10]={
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},      //入口4行2列
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,1,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,0,1,0,1},
    {1,0,1,1,1,0,0,1,1,1},
    {1,1,0,0,0,0,0,0,0,1},      //出口11行8列
    {1,1,1,1,1,1,1,1,1,1},
    };                          //"1"为墙块，"2"为空格
    //顺序栈实现
    typedef struct
    {
        int i;      //行号
        int j;      //列号
        int di;     //下一可走相邻方位的方位号
    }Box;

    typedef struct
    {
        Box data [MaxSize];
        int top;
    }StType;

    /*走位试探顺序
    方块0:  (i-1,j)
    方块1： (i,j+1)
    方块2： (i+1,j)
    方块3:  (i,j-1)
    0-> 1 -> 2 -> 3
    */

   /*方法：
   当前入口方块进栈
   试探走位，能走就走
   下一位置继续试探走位
   如果都不能走，则回退到上一方块，重新选择路径
   */
  bool mgpath(int xi, int yi,int xe,int ye){        //入口：(xi,yi) 出口：(xe,ye)
      int i,j,k,di,find;
      StType st;
      st.top=-1;
      st.top++;         //定义顺序栈，并让入口进栈
      st.data[st.top].i=xi;
      st.data[st.top].j=yi;     //定义初始块位置进栈
      st.data[st.top].di=-1;
      mg[xi][yi]=-1;        //避免重复
      while (st.top>-1)     //栈不空循环
      {
          i=st.data[st.top].i;
          j=st.data[st.top].j;
          di=st.data[st.top].di;        //取栈顶方块
          if (i==xe&&j==ye)             //找到出口啦！！！
          {
              printf("迷宫路径如下：\n");
              for (k = 0; k < st.top; k++)
              {
                  printf("\t(%d,%d)",st.data[k].i,st.data[k].j);        //输出路径
                  if((k+1)%5==0)
                    printf("\n");           //每5个换行
              }
              printf("\n");
              return true;
          }
          find =0;              //找路或者卡路了
          while (di<4&&find==0)     //试探走位或者回退重新找
          {
              di++;
              switch (di)
              {
              case 0: i=st.data[st.top].i-1;j=st.data[st.top].j;
                  break;
              case 1: i=st.data[st.top].i;j=st.data[st.top].j+1;
                  break;
              case 2: i=st.data[st.top].i+1;j=st.data[st.top].j;
                  break;
              case 3: i=st.data[st.top].i;j=st.data[st.top].j;
                  break;
              }
              if(mg[i][j]==0)find=1;        //不是死路，跳出试探走位
          }
          if (find==1)
          {
              st.data[st.top].di=di;        //修改原栈顶元素di
              st.top++;                     //下一个可走方块进栈
              st.data[st.top].i=i;
              st.data[st.top].j=j;
              st.data[st.top].di=-1;
              mg[i][j]=-1;                  //避免重复走到该方块
          }
          else                  //无路可走
          {
              mg[st.data[st.top].i][st.data[st.top].j]=0;
              st.top--;
          }
      }
      return false;
  }
 int main(){
     if(!mgpath(1,1,8,8))
        printf("该迷宫问题无解!");
    return 1;
 } 