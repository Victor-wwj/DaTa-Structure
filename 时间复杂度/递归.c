void fun(int a[],int n,int k)
{
  int i;
  if(k==n-1)
  {
    for(i=0;i<n;i++)
      printf("%d\n,a[i]");
  }
  else
  
  {for(i=k;i<n;i++)
      a[i]=a[i]+i*i;
   fun(a,n,k+1);
  }
 }
 
 //跟着节奏走，仍然设执行次数为 Tn
 //Tn = T1(n,0) = n+T2(n,1) = n+(n-1)+T3(n,2) = ... 
 //=n+(n-1)+(n-2)+...+2+Tn(n,n-1)
 //=(n+2)(n-1)/2+n = n^2/2+3n/2-1
 //O(n^2)
