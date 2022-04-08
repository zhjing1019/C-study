/*
 * 小数形式与科学记数法转换
 *
 * 编写一个程序，将用小数表示的浮点数，转换
 * 成科学计数法的形式输出。输入的数据没有符
 * 号，小数点前后必有数字，且全为有效数据，
 * 即小数点后的末尾数字不为0；小数点前若只
 * 有一位数字，可以为0，否则小数点前的最高
 * 位数字不为0。
 * */

#include<stdio.h>
#include<string.h>
int main(){
    char A[101] = {0};
    gets(A);
    int lenth = strlen(A);
    //ָ��Ϊ��
    if(A[0] == '0')
    {
        int num0 = 0;
        while(A[num0+2] == '0')
            num0++;
        printf("%c",A[num0+2]);
        if(num0 + 3 == lenth)
        {
            printf("e-%d",num0+1);
        }
        else if(num0 + 3 < lenth)
        {
            printf(".");
            for(int i=num0+3;i<lenth;i++)
            {
                printf("%c",A[i]);
            }
            printf("e-%d",num0+1);
        }
    }
    else
    {
        int num = 0;
        while(A[num+1] != '.' && num+1 < lenth)
            num++;
        printf("%c",A[0]);
        if(lenth == 1)
            printf("e0");
        else{
            printf(".");
            for( int i = 1;i<lenth;i++){
                if(A[i] == '.')
                    continue;
                printf("%c",A[i]);
            }
            printf("e%d",num);
        }

    }
    return 0;
}