/*
 * 字符串替换（新）
 * 编写程序将一个指定文件中某一字符串替换为另一个字符串。要求：（1）被替换字符串若有多个，均要被替换；（2）指定的被替换字
符串，大小写无关。
【输入形式】
给定文件名为filein.txt。从控制台输入两行字符串（不含空格，行末尾都有回车换行符），分别表示被替换的字符串和替换字符串。
【输出形式】
将替换后的结果输出到文件fileout.txt中。
 * */

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MaxLine 1024

void replace(char *line,char *newline,char *Old,char *New){
    int lenthline = strlen(line);
    int lenthOld = strlen(Old);
    int lenthNew = strlen(New);
    int i,j,point=0;
    for(i=0;i<lenthline;i++){
        for(j=0;j<lenthOld;j++)
        {
            if(tolower(line[i+j]) == tolower(Old[j]))
                continue;
            else
                break;
        }
        if(j == lenthOld){
            i = i + lenthOld-1;
            int k = 0;
            while(k<lenthNew){
                newline[point] = New[k];
                point++;
                k++;
            }
        }
        else
            newline[point++] = line[i];
    }

}

int main(){
    FILE *fp1;
    FILE *fp2;
    char Old[64]={0};
    char New[64]={0};
    char line[MaxLine]={0};
    char newline[MaxLine]={0};
    gets(Old);
    gets(New);
    if((fp1 = fopen("filein.txt","r")) == NULL)
    {
        printf("Can't open file filein.txt");
        return 1;
    }
    if((fp2 = fopen("fileout.txt","w")) == NULL)
    {
        printf("Can't open file fileout.txt");
        return 1;
    }
    while(fgets(line,MaxLine-1,fp1) != NULL)
    {
        memset(newline,0,sizeof(newline));
        replace(line,newline,Old,New);
        fputs(newline,fp2);
        memset(line,0,sizeof(line));
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}