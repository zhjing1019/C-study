/*
 * 计算器（表达式计算-后缀表达式实现）
    【问题描述】
    从标准输入中读入一个整数算术运算表
    达式，如24 / ( 1 + 5%3 + 36 / 6 / 2 - 2) * ( 12 / 2 / 2 )= ，计算表达式结果，并输
    出。
 * */

#include<stdio.h>
#include<string.h>

typedef struct stock{
    int type;
    union {
        int number;
        char operation;
    }value;
}stock;

int is_opera(char c){
    if(c=='+' || c =='-' || c=='*' || c=='/' || c=='%')
        return 1;
    return 0;
}

int level(char c){
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/' || c=='%')
        return 2;
    return 0;
}

int Token(char *A,char *s1,stock *s2){
    int point1 = 0,point2 = 0;
    int number = 0;
    for(int i=0;i<strlen(A);i++){
        if(A[i]>='0' && A[i]<='9'){
            number = 0;
            while(A[i]>='0' && A[i]<='9'){
                number = number * 10 + A[i] - '0';
                i++;
            }
            i--;
            s2[point2].type = 1;
            s2[point2].value.number = number;
            point2++;number = 0;
        }

        else if(A[i] == ' ')
            continue;
        else if(is_opera(A[i]) == 1)
        {
            while(1){
                if(strlen(s1)==0 || s1[point1]=='(') {
                    s1[point1] = A[i];
                    point1++;
                    break;
                }
                else if(level(A[i]) > level(s1[point1-1]))	{
                    s1[point1] = A[i];
                    point1++;
                    break;
                }
                else{
                    char c = s1[point1-1];
                    s2[point2].type = 0;s2[point2].value.operation = c;point2++;
                    s1[point1-1] = 0;point1--;
                }
            }
        }
        else if(A[i]=='(' || A[i]==')'){
            if(A[i]=='('){
                s1[point1] = A[i];
                point1++;
            }
            else{
                point1--;
                while(s1[point1] != '('){
                    char c = s1[point1];
                    s2[point2].type = 0;s2[point2].value.operation = c;point2++;
                    s1[point1] = 0;point1--;
                }
                s1[point1] = 0;
            }
        }
    }
    point1--;
    while(point1 >= 0){
        char c = s1[point1];
        s2[point2].type = 0;s2[point2].value.operation = c;point2++;
        s1[point1] = 0;point1--;
    }

    return point2;
}

int calculate(int a,int b,char c){
    if(c == '+')
        return a+b;
    else if(c == '-')
        return a-b;
    else if(c == '*')
        return a*b;
    else if(c == '/')
        return a/b;
    else if(c == '%')
        return a%b;
}

int main(){
    char A[1000] = {0};
    gets(A);
    char s1[1000] = {0};
    stock s2[1000];

    int point = Token(A,s1,s2);
    int result[1000] = {0};int p = 0;
    for(int i=0;i<point;i++){
        if(s2[i].type == 1){
            result[p] = s2[i].value.number;
            p++;
        }
        if(s2[i].type == 0){
            char c = s2[i].value.operation;
            int a = result[p-2],b = result[p-1];
            result[p-2] = result[p-1] = 0;
            p -= 2;
            result[p] = calculate(a,b,c);
            p++;
        }
    }
    printf("%d",result[0]);
    return 0;
}