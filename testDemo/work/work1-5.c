/*
 * 全排列数的生成
 *
 * 输入整数N( 1 <= N <= 10 )，生
 * 成从1~N所有整数的全排列。
 * */

#include <stdio.h>

int list[11];

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void perm(int k, int m)
{
    int i;
    if(k == m) {
        for(i = 0; i <= m; i++)
            printf("%d ", list[i]);
        printf("\n");
    }
    else
    {
        for(i = k; i <= m; i++)
        {
            for (int j = i-1; j >= k; j--)
                swap(&list[j], &list[j+1]);
            perm(k + 1, m);
            for (int j = k; j <= i-1; j++)
                swap(&list[j], &list[j+1]);
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        list[i] = i + 1;
    }
    perm(0, n-1);

    return 0;
}
