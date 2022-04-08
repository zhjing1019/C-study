// 将一个磁盘文件中的信息复制到另一个磁盘文件中，要求将上例建立的file1.dat文件中的内容复制到另一个磁盘文件file2.dat中
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *in, *out;
    char ch, infile[10], outfile[10];
    printf("输入读入文件的名字");
    scanf("%s", infile);
    printf("输入输出文件的名字");
    scanf("%s", outfile);
    if ((in = fopen(infile, "r")) == NULL)
    {
        printf("无法打开此文件");
        exit(0);
    }
    if ((in = fopen(outfile, "w")) == NULL)
    {
        printf("无法打开此文件");
        exit(0);
    }
    while(!feof(in))        //如果未遇到输入文件的结束标志
    {
        ch = fgetc(in);     //从输入文件读入一个字符，暂放在变量ch中
        fputc(ch, out);     //将ch写到out文件中
        putchar(ch);        //将ch打印到屏幕上
    }
    putchar(10);            //显示完全部字符后换行
    fclose(in);             //关闭输入文件
    fclose(out);            //关闭输出文件
    return 0;
}