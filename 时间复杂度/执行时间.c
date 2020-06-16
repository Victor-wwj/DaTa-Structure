//
//  main.c
//  算法时间复杂度分析
//
//  Created by Victor's black-apple on 2020/6/11.
//  Copyright © 2020 Victor's black-apple. All rights reserved.
//

#define MAX 20
void matrixadd(int n,int A[MAX][MAX],int B[MAX][MAX],int C[MAX][MAX])
{
    int i,j;
    for(i=0;i<n;i++)                        //频度 n+1
        for(j=0;j<n;j++)                    //频度n*(n+1)
            C[i][j]=A[i][j]+B[i][j];        //频度n^2
}

//计算执行时间T(n)
//T(n)= n+1+n*（n+1）+n^2 = 2n^2+2n+1
//时间复杂度取最高数量级，记为O(n^2)
