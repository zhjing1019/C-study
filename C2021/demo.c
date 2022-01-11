// 已知二叉树采用二叉链表存储结构，根结点的地址为T，请写出一非递归算法，统计出该二叉树中度为1的节点数目，要求用到堆栈采用链式存储结构
// 利用二叉树的遍历操作，前序遍历，在遍历的过程中每访问一个节点就判断该节点是否只存在一颗子树，同时记录（前序遍历）
typedef struct node
{
    BTREE data;
    struct node *link;
}BLNode, *BTLinkList;
int main (BTREE T)
{
    int n;
    BTLinkList q, top = NULL;
    BTREE p = T;
    do{
        while(p != NULL)
        {
            if---
              n++
            q -> data = p;
            q -> link = top;
            top = q;
            p = p -> lchild;
        }
        p -> data = top -> data;
        top = q -> link;
        free(q);
        p = p -> rchild;
    }while(!(top == NULL && p == NULl))
}

// 后序遍历
//　已知非空二叉树采用二叉链表存储结构，根结点地址为T，请写出非递归算法，该算法打印数据信息为item的节点所有的祖先节点，假设数据信息为item的节点不多于一个
// 这里为了简化算法，假设每个节点的数据信息为一个十进制整数。根据定义，一个节点的祖先定义为根结点到该节点的双亲节点路径上的所有节点。因此本题利用后续遍历二叉树的非递归算法达到目的
// 在遍历的过程中，当找到满足条件的节点时，堆栈中依次保存的就是该节点的祖先节点
#define NodeNum 100;
void fun(Btree T) {
    Btree stack1[NodeNum], p = T;
    int stack2[NodeNum], flag, top = -1;
    if(T != NULL && T -> data != item)
    {
        do {
            while(p != NULL)
            {
                stack1[++top] = p;
                stack2[top] = 0;
                p = p -> lchild
            }
            // 退栈
            p = stack1[top];
            flag = stack2[top--];
            if(flag == 0) {
                // 进栈
                stack1[++top] = p;
                stack2[top] = 1;
                p = p -> rchild
            } else {
                if(p -> data == item)
                {
                    while(top >= 0)
                    {
                        print('%d', stack1[top--] -> data)
                    }
                }
            }

        }
    }
}

// 从键盘输入一些字符，逐个把他们送到磁盘上去，直到用户输入一个"#"为止
#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fp;
    char ch; fileName[10];
    printf("please enter your filename!");
    scanf("%s", &fileName);
    if(fp = fopen(fileName, "w") == NULL)
    {
        printf("cannot open this file!");
        exit(0)
    }
    ch = getchar();
    printf("please enter char, and end of #");
    while(ch != '#')
    {
        fputc(ch, fp);
        putchar(ch);
        ch = getchar();
    };
    fclose(fp);
    putchar(10);
    return 0;
}

// 将一个磁盘文件中的信息复制到另一个磁盘文件中，要求将上例建立的file1.dat文件中的内容复制到另一个磁盘文件file2.dat中
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *in, *out;
    char inFileName[20], outFileName[20], ch;
    printf("please enter in fileName");
    scanf("%s", inFileName);
    printf("please enter out fileName");
    scanf("%s", outFileName);
    if(in = fopen(inFileName, "r") == NULL)
    {
        printf("cannot open");
        exit(1);
    }
    if(in = fopen(outFileName, "w") == NULL)
    {
      printf("cannot open");
      exit(1);
    }
    while(!feof(in))
    {
        ch = fgetc(in);
        fputc(ch, outFileName);
        putchar(ch);
    }
    putchar(10);
    fclose(in);
    fclose(out);
    return 0;
}

// 从键盘读入若干个字符串，对他们按照字母大小的顺序排序，然后把排好序的字符串送到磁盘文件中保存
// 用选择排序对字符串排序
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *fp;
    char str[5][20]; temp[20];
    int i, j, k, n = 5;
    printf("enter string");
    for(i = 0; i < n; i++)
        gets(str[i]);
    // 选择排序
    for(i = 0; i < n - 1; i++)
    {
        k = i;
        for(j = i + 1; j < n; j++)
        {
            if(strcmp(str[k], str[j]) > 0)
                k = j;
        }
        if (k != i)
        {
            strcpy(temp, str[i]);
            strcpy(str[i], str[k]);
            strcpy(str[k], temp);
        }
    }
    if(fp = fopen(fp, "w") == NULL)
    {
        printf("cannot open");
        exit(0)
    }
    for(i = 0; i < n; i++)
    {
        fputs(str[i], fp);
        fputs("\n", fp);
        printf("%s", str[i])
    }
    return 0;
}
// 对于给定的任意无符号十进制整数num，如何依次输出与其等值的八进制数
// 将num除以8，取余数
// 判断商是否为0，若是0，转换结束，若不是0，将商送到num转第一步
void CON(int num)
{
    int STACK[], top = -1;
    do{
        STACK[++top] = num % 8;
        num = num / 8;
    }while(num != 0)
}
