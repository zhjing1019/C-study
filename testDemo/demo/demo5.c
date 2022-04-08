// 设中缀表达式E存放于字符数组中，并以@作为结束标志符，请写出判断一个中缀表达式E中左右圆括号是否匹配的算法
// 需要从左到右依次进行扫描，扫描 遇到左边括号进栈，遇到右边括号退栈，最后，若栈空，则匹配

//以下为算法的实现

#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 100

typedef struct{
    char *base;//栈底指针
    char *top;//栈顶指针的下一指针
    int StackSize;//顺序栈的最大空间量,意味着所能判断括号数量的最大值是100-1=99
}sqStack;//顺序栈S的的结构构体

int BracketInspect(sqStack *S)
{//括号检验的函数,合法返回值为1,非法返回值为0
    char Bracket;
    S->StackSize=MAXSIZE;
    S->base=(char *)malloc(S->StackSize*sizeof(char));
    S->top=S->base;//以上为结构体的完善
    do{//算法的核心部位
        scanf("%c",&Bracket);//这里不可以用getchar(),否则会存在bug,错误
        switch(Bracket){
            case '(':*S->top++='(';break;
            case '[':*S->top++='[';break;
            case '{':*S->top++='{';break;//以上为左括号的情况
            case ')'://以下为右括号的情况
                if(S->top==S->base)return 0;
                if(*(S->top-1)!='(')return 0;
                if(*(S->top-1)=='(')--S->top;break;//退栈，仅仅只是将S.top的指向前移，内容并未改变
            case ']':
                if(S->top==S->base)return 0;
                if(*(S->top-1)!='[')return 0;
                if(*(S->top-1)=='[')--S->top;break;
            case '}':
                if(S->top==S->base)return 0;
                if(*(S->top-1)!='{')return 0;
                if(*(S->top-1)=='{')--S->top;break;
            default:;
        }
    }while(Bracket!='\n');
    if(S->top==S->base)
        return 1;//最终退栈为空则为匹配成功
    else return 0;//匹配失败
}
int main()
{sqStack *S;
    S=(sqStack *)malloc(sizeof(sqStack));
    int idea=BracketInspect(S);
    printf("%d",idea);
    return 0;
}

//例如:  5+[(3+2)*2-1]/2
//结果为1  代表着匹配成功
//例如:  (5+2))*3
//结果为0  代表着匹配失败
