/*
**Unix操作系统中有一条命令，该命令的功能是打印文本文件的最后n行。命令格式为
**     tail [-n] filename
**其中。tail为命令名：参数filename为文本文件名；参数[-n]表示要打印的行数，该参数是可选的，缺省值为10，即无此参数时，表示打印文件的最后10行。
**  例如，命令
**      tail -20 exapmle.txt
** 表示要打印文本文件example.txt的最后20行。
** 请用C语言实现该程序。要求：该程序应该具有一定的错误处理能力，例如处理非法命令行参数和非法文件名 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFLINES 10       //n的缺省值是10；
#define MAXLEN 100        //假设一行最大长度是100；

struct Tail
{
    char data[MAXLEN];
    struct Tail *link;
};

int main(int argc, char *argv[])
{
    char curline[MAXLEN], *filename;
    int n = DEFLINES;                       //n的缺省值是10
    struct Tail *list, *ptr, *qtr;
    FILE *fp;

    if(argc == 3 && argv[1][0] == '-')    //进行命令行的参数正确性检查
    {
        n = atoi(argv[1] + 1);            //将字符类型的n转化为整数类型的n
        filename = argv[2];
    }
    else if(argc == 2) 
        filename = argv[2];
    else
    {
        /* 命令行本身有错 */
        fprintf(stderr, "Usage:tail [-n] filename\n");
        exit(1); 
    }
    if((fp = fopen(filename, "r")) == NULL)
    //以只读方式打开文本文件并检查文件是否能够打开
    {
        fprintf(stderr, "Cannt open file:%s! \n");
        exit(-1);
    }
    list  = qtr = (struct Tail *)malloc(sizeof(struct Tail));
    qtr->data[0] = '\0';
    for(int i = 1; i < n; i++)
    {
        ptr = (struct Tail *)malloc(sizeof(struct Tail));
        ptr->data[0] = '\0';
        qtr->link = ptr;
        qtr = ptr;
    }

    ptr->link = list;
    //建立一个不带头节点的单向循环链表，并将各个节点的数据清空
    ptr = list;
    while(fgets(curline, MAXLEN, fp) !=NULL)
    //将文本文件中的一行读入curline中，直到文件尾
    {
        strcpy(ptr->data, curline);
        ptr = ptr->link;
    }
    for(int i = 0; i < n; i++)
    {
        if(ptr->data[0] != '\0')
            printf("%s", ptr->data);
        ptr = ptr->link;
    }
    fclose(fp);
    ptr = list->link;   //释放单向循环链表
    if(ptr !=list)
    {
        free(ptr);
        ptr = ptr->link;
    }
    free(list);
    exit;

    return 0;
};