## 0递归

### 何时调用递归

#### 定义是递归的

如：n！、Fibonacci数列

```c++
int Fibi(int n){

  if (n==1||n==2)

​    return 1;

  else

​    return (Fibi(n-1)+Fibi(n-2));  

}
```



#### 数据结构是递归的

头指针制“大”单链表，next指针指“小”单链表（不带头节点）

```c++
typedef struct LNode
{

  int data;

  struct LNode * next;

}LinkList;
```



#### 问题求解方法是递归的

Hanoi问题：盘塔

```c++
void hanoi(int n,char A,char B,char C)

{

  hanoi(n-1,A,C,B);    //把n-1个盘从A移到B借助C

  hanoi(n-1,B,A,C);    //把n-1个盘从B移到C借组A

}
```

时间复杂度分析：

```
Tn=1   当n=1时

Tn=2T(n-1)+1

 =2(2T(n-2)+1)+1=2^2(2T(n-2)+1)+2+1

 =2^3T(n-3)+2^2+2+1

 =...

 =2^n-1T(1)+2^n-2+...+2^2+2+1

 =2^n-1

 =O(2^n)
```

#### 递归模型

求n！递归算法的递归模型

```c++ 
fun(1)=1;				//递归出口
fun(n)=n*fun(n-1);	    //递归体
```

求实数数组A[0…n-1]中的最小值

```C++
float f(float A[],int i){
	float m;			
	if(i==0)			
		return A[0];		//递归出口
    
	else{
	m=f(A,i-1);
	if(m>A[i])
		return A[i];		//递归体
	else
		return m;
	}
}
```

求单链表（不带头节点）中数据节点个数

```C++
int count(Node *L){
	if(L==Null)
		return 0;		//递归出口
	else
		return count(L->next)+1;	//递归体
}
```

求迷宫问题所有路径

```C++
typedef struct{
	int i;		//当前方块的行号
	int j;		//当前方块的列号
}Box;

typedef struct{
	Box data[MaxSize];
	int length;			//路径长度
}PathType;

void mgpath(int x,int y,int xe,int ye,PathType path){
    int di,k,i,j;
    if(xi==xe&&yi==ye){			//找到出口，输出一条路径（递归出口）
        path.data[path.length].i=xi;
        path.data[path.length].j=yi;
        path.length++;
        printf("迷宫路径%d如下：\n",++count);
        for(k=0;k<path.length;k++){
            printf("\t(%d,%d)",path.data[k].i,path.data[k].j);
            if((k+1)%5==0)printf("\n");
        }else{
            if(mg[xi][yi]==0){
                di=0;
                while(di<4){
                    switch(di){
                        case 0:i=xi-1;j=yi;break;
                        case 1:i=xi;j=yi+1;break;
                        case 2:i=xi+1;j=yi;break;
                        case 3:i=xi;j=yi-1;break;
                    }
                    path.data[path.length].i=xi;
                    path.data[path.length].j=yi;
                    path.length++;
                    mg[xi][yi]=-1;
                    mgpath(i,j,xe,ye,path);		//递归调用小问题
                    path.length--;				//回退一个方块
                    mg[xi][yi]=0;			//恢复(xi,yi)为可走
                    di++;
                }
            }
        }
    }
}
```

```c++
大问题=走一步+小问题

若(xi,yi)=(xe,ye)
mgpath(xi,yi,xe,ye,path)=将(xi,yi)添加到path中；输出path中的迷宫路径;
若(xi,yi)不为出口且可走
mgpath(xi,yi,xe,ye,path)=对于(xi,yi)四周的每一个相邻方块(i,j)
							1、将(xi,yi)添加到path中;
							2、置mg[xi][yi]=-1;
							3、mgpath(i,j,xe,ye,path);
							4、path回退一步并置mg[xi][yi]=0;
```



##### 总结：

采用递归方法求解问题时，需要对问题本身进行分析，确定大、小问题解之间的关系，构造合理的递归体。