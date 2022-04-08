/*
 * 超长正整数的减法
 * 编写程序实现两个超长正整数（每个最长80位
 * 数字）的减法运算。
 *
 * 【输入形式】
 * 从键盘读入两个整数，要考虑输入高位可能为
 * 0的情况（如00083）。
 * 1. 第一行是超长正整数A； 2. 第二行是超长正整数B；
 * */
#include<stdio.h>
#include<string.h>
int flag = 1;
int Compare(char *A1,char *B1){
    int la = strlen(A1);
    int lb = strlen(B1);
    if(la > lb)
        return 11;
    else if(la < lb)
        return -11;
    else{
        for(int i = 0;i < la;i++){
            if(A1[i] > B1[i])
                return 10;
            else if(A1[i] < B1[i])
                return -10;
            else
                continue;
        }
        return 0;
    }
}

int main(){
    char A[81] = {0};
    char B[81] = {0};
    char A1[81] = {0};
    char B1[81] = {0};
    char result[81] = {0};
    gets(A);
    gets(B);

    int a=0,b=0;
    int la = strlen(A);
    int lb = strlen(B);
    while(A[a] == 0 && a<la)
        a++;
    while(B[b] == 0 && b<lb)
        b++;
    for(int i=a;i<la;i++)
        A1[i-a] = A[i];
    for(int i=b;i<lb;i++)
        B1[i-b] = B[i];
    if(a == la)
        A1[0] = 0;
    if(b == lb)
        B1[0] = 0;

    la = strlen(A1)-1;
    lb = strlen(B1)-1;
    int judge = Compare(A1,B1);

    if(judge == 11){
        int r = 0;
        a = la;b = lb;
        while(b >= 0){
            if(A1[a] >= B1[b]){
                result[r] = A1[a]-B1[b]+'0';
                r++;
            }
            else{
                result[r] = A1[a]-B1[b]+10+'0';
                r++;
                A1[a-1] = A1[a-1] - 1;
            }
            a--;
            b--;
        }
        while(a >= 0){
            if(A1[a]<'0'){
                A1[a] = A1[a]+10;
                result[r] = A1[a];
                A1[a-1] = A1[a-1]-1;
            }
            else
                result[r] = A1[a];
            a--;
            r++;
        }
    }
    else if(judge == -11){
        flag = -1;

        int r = 0;
        a = la;b = lb;
        while(a >= 0){
            if(B1[b] >= A1[a]){
                result[r] = B1[b]-A1[a]+'0';
                r++;
            }
            else{
                result[r] = B1[b]-A1[a]+10+'0';
                r++;
                B1[b-1] = B1[b-1] - 1;
            }
            a--;
            b--;
        }
        while(b >= 0){
            if(B1[b]<'0'){
                result[r] = B1[b]+10;
                B1[b-1] = B1[b-1] - 1;
            }
            else
                result[r] = B1[b];
            b--;
            r++;
        }
    }
    else if(judge == -10){
        flag = -1;

        int r = 0;
        a = la;b = lb;
        while(a >= 0){
            if(B1[b] >= A1[a]){
                result[r] = B1[b]-A1[a]+'0';
                r++;
            }
            else{
                result[r] = B1[b]-A1[a]+10+'0';
                r++;
                B1[b-1] = B1[b-1] - 1;
            }
            a--;
            b--;
        }
    }
    else if(judge == 10){
        int r = 0;
        a = la;b = lb;
        while(b >= 0){
            if(A1[a] >= B1[b]){
                result[r] = A1[a]-B1[b]+'0';
                r++;
            }
            else{
                result[r] = A1[a]-B1[b]+10+'0';
                r++;
                A1[a-1] = A1[a-1] - 1;
            }
            a--;
            b--;
        }
    }
    int lr = strlen(result);
    int r = lr-1;
    while(result[r] == '0' && r>=0)
        r--;
    if(r == -1)
        printf("0");
    else{
        if(flag == -1)
            printf("-");
        for(int i = r;i>=0;i--)
            printf("%d",result[i]-'0');
    }
    return 0;
}
