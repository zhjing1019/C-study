/*
 * 栈操作（栈-基本题）
 * 假设给定的整数栈初始状态为空，栈的最大容
量为100。从标准输入中输入一组栈操作，按
操作顺序输出出栈元素序列。栈操作：1表示
入栈操作，后跟一个整数（不为1、0和-1）为
入栈元素；0表示出栈操作；-1表示操作结
束。
 * */

#include<stdio.h>
int main(){
    int stack[101]={0};
    int point = 0;
    int operation = 0,number = 0;
    while(operation != -1){
        scanf("%d",&operation);
        switch(operation){
            case 1:
                scanf("%d",&number);
                if(point == 100){
                    printf("error ");
                    break;
                }
                point++;
                stack[point] = number;
                break;
            case 0:
                if(point == 0){
                    printf("error ");
                    break;
                }
                printf("%d ",stack[point]);
                stack[point] = 0;
                point--;
                break;
            case -1:
                break;
            default:
                printf("operation not included");
                break;
        }
    }
    return 0;
}