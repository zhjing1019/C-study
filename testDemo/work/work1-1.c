/*
 * 表达式计算（支持空格，连乘，连除）
 * 【问题描述】
 * 从标准输入中读入一个整数算术运算表达式，如5 - 1 * 2 * 3 + 12 / 2 / 2 = 。计算表达式结果，并输出。
 * */

#include<stdio.h>

char Token[1000][10] = {0};
int point = 0;
int output = 0;

void Tokenizer(char *Exp){
    int index = 0;
    point = 0;
    for(int i=0; Exp[i]!='=' ;i++){
        if(Exp[i] >= '0' && Exp[i] <= '9'){
            Token[point][index] = Exp[i];
            index++;
        }
        else if(Exp[i] == ' ')
            continue;
        else{
            index = 0;
            point++;//����һ��Token���뱾��Token
            Token[point][index] = Exp[i];
            point++;//����Token������������һ��Token
        }
    }
    point = 0;//ָ���λ��
}

int calculate(int a,int b,char c){
    switch(c){
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return a * b;
            break;
        case '/':
            return a / b;
            break;
        default:
            return 0;
    }
}

// 字符串转换成数字
int translate(){
    int result = 0;int index = 0;
    while(Token[point][index] >= '0' && Token[point][index] <= '9'){
        result = result * 10 + (Token[point][index] - '0');
        index++;
    }
    return result;
}

int MultiAnalyse(){
    int a = translate();
    point++;
    while(Token[point][0] == '*' || Token[point][0] == '/') {
        char c = Token[point][0];
        point++;
        int b = translate();
        a = calculate(a,b,c);
        point++;
    }
    return a;
}

int AddiAnalyse(){
    int a = MultiAnalyse();
    while(Token[point][0] == '+' || Token[point][0] == '-') {
        char c = Token[point][0];
        point++;
        int b = MultiAnalyse();
        a = calculate(a,b,c);
    }
    return a;
}

void Analyser(){
    output = AddiAnalyse();
}


int main(){
    char Exp[10000] = {0};
    gets(Exp);
    Tokenizer(Exp);
    Analyser();
    printf("%d",output);

    return 0;
}
