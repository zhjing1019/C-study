// 变量属性的使用
// auto存储在程序栈中,不能声明全局变量
// static存储在全局作用域，只是声明的文件中，存贮在静态区中,只会被初始化一次，作用域是在函数内，但是static的生命周期是程序的运行周期
// register变量请求存储于CPU寄存器中，全局变量的属性不可能为register，实时性要求高的变量，尽量选择寄存器变量
#include <stdio.h>
int g = 0;
int m = 0;
extern int test2_g;
// extern int test1_s;
extern int test2_func();
void f1()
{
    int i = 0;
    i++;
    printf("%d\n", i);
}
void f2() {
    static int i = 0;
    i++;
    printf("%d\n", i);
}
int main()
{

    auto int i = 0;
    register int j = 0;
    static int k = 0;
    // for (i = 0; i < 5; i ++)
    // {
    //     f1();
    // }
    // for(i = 0; i<5; i++)
    // {
    //     f2();
    // }
    printf("%d\n", test2_g);
    printf("%d\n", test2_func());
    // printf("%d\n", test1_s);
    return 0;
} 