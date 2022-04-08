/*
 * 加密文件
【问题描述】有一种加密方法为：其使用一个字母串（可以含重复字母，字母个数不超过50）作为密钥。假定密钥单词
串为feather，则先去掉密钥单词中的重复字母得到单词串feathr，然后再将字母表中的其它字母以反序追加到feathr的后
面：
 * */

#include<stdio.h>
#include<string.h>

int if_in(char *A,char c){
    for(int i=0;i<strlen(A);i++)
        if(A[i] == c)
            return 1;
    return 0;
}

void Key(char code[][27],char *word){
    int point = 0;
    char list[27] = {0};
    for(int i=0;i<strlen(word);i++){
        int flag = 1;
        for(int j=0;j<i;j++){
            if(word[i] == word[j])
            {
                flag = -1;
                break;
            }
        }
        if(flag == 1 && word[i]>='a' && word[i]<='z')
            list[point++] = word[i];
    }
    for(int i=0;i<point;i++)
        code[1][i] = list[i];
    char c = 'z';
    while(point<26)
    {
        if(!if_in(list,c)){
            code[1][point] = c;
            point++;
        }
        c--;
    }
}

int main(){
    FILE *in;
    FILE *out;
    char code[2][27] = {"abcdefghijklmnopqrstuvwxyz"};
    char word[51] = {0};
    gets(word);
    if((in=fopen("encrypt.txt","r")) == NULL){
        printf("Can't open file encrypt.txt");
        return 1;
    }
    if((out=fopen("output.txt","w")) == NULL){
        printf("Can't open file output.txt");
        return 1;
    }
    Key(code,word);
    for(int i=0;i<26;i++)
        printf("%c",code[1][i]);
    char c;
    while((c=fgetc(in)) != EOF){
        if(c<'a' || c>'z')
            fputc(c,out);
        else
            fputc(code[1][c-'a'],out);
    }
    fclose(in);
    fclose(out);
    return 0;
}