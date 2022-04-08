/*
 * 立方根的逼近迭代方程是 y(n+1) = y(n)*2/3 + x/(3*y(n)*y(n)),其中y0=x.求给定的x经过n次迭代后立方根的值。
 * 输出描述:
 * 迭代n次后的立方根，double精度,保留小数点后面六位。
 * */

#include<stdio.h>

int main()
{
    double x;
    int n;
    while(scanf("%lf %d",&x,&n)!=EOF)
    {
        double y=x;
        for (int i=0; i<n; i++)
            y=y*2/3+x/(3*y*y);
        printf("%.6lf\n",y);
    }
    return 0;
}