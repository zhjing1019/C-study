// 求5的阶乘 5!
//int t, i;
//t = 1;
//i = 2;
//while (i <= 5)
//{
//t *= i;
//i++;
//}
//printf("%d\n", t);



//给定一个大写字母，要求用小写字母输出
//char c1, c2;
//c1 = 'A';
//c2 = c1 + 32;
//printf("%c\n", c1);
//printf("%c\n", c2);



// C语言的斐波那契数列
//int main()
//{
//    int f1 = 1, f2 = 1, f3, i;
//    printf("%d\n%d\n",f1,f2);
//    for(i = 1; i < 38; i++)
//    {
//        f3 = f1 + f2;
//        printf("%d\n",f3);
//        f1 = f2;
//        f2 = f3;
//    }
//    return 0;
//}

// *****对一个数组从小到大的排列 （冒泡排序,俩俩比较，俩俩交换，大的往后冒泡）
// *****冒泡排序要经过俩次循环
//void sort()
//{
//    int i, j;
//    for(j = 0; j < 9; j++ )    //进行9次循环，9躺比较
//    {
//        for(i = 0; i < 9-j; i++)  //每一趟都要进行9-i次比较
//        {
//            if(a[i]>a[i+1])     //相邻俩个数比较
//                t = a[i]; a[i] = a[i+1]; a[i+1] = t;
//        }
//    }
//}


// ****统计有多少个单词，单词之间用空格隔开
#include <stdio.h>
int getWord()
{
    char string[81];
    int i, num = 0, word=0;
    char c;
    gets(string);
    for (i = 0; (c=string[i]) != '\0'; i++)
    {
        if(c == ' ') word = 0;  //word是判断是否是新开始的单词
        else if(word == 0)
        {
            word = 1; num++;
        }
    }
    printf("%d", num);
    return 0;
}

int main() {
    getWord();
    return 0;
}
