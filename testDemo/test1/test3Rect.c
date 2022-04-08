/*
 * 任意输入两个9阶以下矩阵，要求判断第二个是否是第一个的旋转矩阵，如果是，输出旋转角度（0、90、180、270），
 * 如果不是，输出-1。 要求先输入矩阵阶数，然后输入两个矩阵，每行两个数之间可以用任意个空格分隔。
 * 行之间用回车分隔，两个矩阵间用任意的回车分隔。
 *
 * 输入描述:
 * 输入有多组数据。
 * 每组数据第一行输入n(1<=n<=9)，从第二行开始输入两个n阶矩阵。
 * */
#include<stdio.h>
#include<stdlib.h>
int sum=0;
int n,i,j,k,h;
int quarter_0(int A[10][10],int B[10][10],int n)
{
    sum=0;
    for (i=0,k=0; i<n,k<n; i++,k++)
        for(j=0,h=0; j<n,h<n; j++,h++)
            if(A[i][j]==B[k][h])
                sum++;
    if(sum==n*n)
        return 0;
    else return -1;
}
int quarter_1(int A[10][10],int B[10][10],int n)
{
    sum=0;
    for (i=0,h=n-1; i<n,h>=0; i++,h--)
        for(j=0,k=0; j<n,k<n; j++,k++)
            if(A[i][j]==B[k][h])
                sum++;
    if(sum==n*n)
        return 90;
    else return -1;
}
int quarter_2(int A[10][10],int B[10][10],int n)
{
    sum=0;
    for (i=0,k=n-1; i<n,k>=0; i++,k--)
        for(j=0,h=n-1; j<n,h>=0; j++,h--)
            if(A[i][j]==B[k][h])
                sum++;
    if(sum==n*n)
        return 180;
    else return -1;
}
int quarter_3(int A[10][10],int B[10][10],int n)
{
    sum=0;
    for (i=0,h=0; i<n,h<n; i++,h++)
        for(j=0,k=n-1; j<n,k>=0; j++,k--)
            if(A[i][j]==B[k][h])
                sum++;
    if(sum==n*n)
        return 270;
    else return -1;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int A[10][10],B[10][10];
        for (i=0; i<n; i++)
            for(j=0; j<n; j++)
                scanf("%d",&A[i][j]);
        for (i=0; i<n; i++)
            for(j=0; j<n; j++)
                scanf("%d",&B[i][j]);
        int a=quarter_0(A,B,n);
        int b=quarter_1(A,B,n);
        int c=quarter_2(A,B,n);
        int d=quarter_3(A,B,n);
        if(a!=-1)printf("%d\n",a);
        if(a==-1&&b!=-1)printf("%d\n",b);
        if(a==-1&&b==-1&&c!=-1)printf("%d\n",c);
        if(a==-1&&b==-1&&c==-1&&d!=-1)printf("%d\n",d);
        if(a==-1&&b==-1&&c==-1&&d==-1)printf("-1\n");
    }

    return 0;
}
