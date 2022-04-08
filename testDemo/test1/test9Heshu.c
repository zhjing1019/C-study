/*
 * 给定区间[a,b],输出这个区间里最长的连续合数段
 *
 * */

//给定区间[a,b],输出这个区间里最长的连续合数段
//输入两个整数a和b，a, b <= 10000

#include <stdio.h>

//判断是否为合数,1是，0非
int Heshu(int a) {
    for (int i = 2; i < a / 2 + 1; i++)
    {
        if (a % i == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int n = b - a + 1;
    //	;
    int j = 0;
    int k = 0;
    int num[10000], count[3000];
    for (int i = 0; i < n; i++)
    {
        num[i] = Heshu(a + i);
    }
    for (int i = 0; i < n; i++)
    {
        if (num[i] == 1)
        {
            j++;
        }
        else
        {
            count[k] = j;
            count[k + 1] = a+i;
            j = 0;
            k=k+2;
        }
    }
    if (j!=0)
    {
        count[k] = j;
        count[k + 1] = b+1;
        j = 0;
        k = k + 2;
    }

    //最长的只有一组
    int p=0, q=0;
    for (int i = 0; i < k; i=i+2)
    {
        if (count[p]<count[i])
        {
            p = i;
        }
    }
    q = count[p - 1];
    for (int i = 0; i < count[p]; i++)
    {
        printf("%d ", (q + i+1));
    }
    printf("\n");
    //最长的有多组
    int c = p + 2;
    while (c<k)
    {
        if (count[c]==count[p])
        {
            for (int i = 0; i < count[c]; i++)
            {
                printf("%d ", (count[c - 1] + i + 1));
            }
            printf("\n");
        }

        c = c + 2;
    }
    return 0;
}
