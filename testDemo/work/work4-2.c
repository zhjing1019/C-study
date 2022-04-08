/*
 * C程序括号匹配检查
 * 编写一程序检查C源程序文件中{}、()等
括号是否匹配,并输出第一个检测到的不
匹配的括号及所对应括号所在的行号
（程序中只有一个括号不匹配）。
 * */

#include<stdio.h>
#include<string.h>

typedef struct brace{
    int line;
    char shape;
}brace;

int is_brace(char c){
    if(c == '{' || c == '}' || c == '(' || c == ')')
        return 1;
    return 0;
}

int main(){
    FILE *in;
    if((in = fopen("example.c","r")) == NULL){
        printf("file does not exist");
    }
    brace stock[200],save[200];
    char input[201] = {0};
    int lin = 1,count = 0,flag = 1;

    while(fgets(input,200,in) != NULL){
        char c = 0;
        for(int i=0;i<strlen(input);i++){
            c = input[i];

            if(c == '*' && input[i+1] == '/'){
                flag = 1;
                i++;
                continue;
            }
            if(flag == 0)
                continue;

            if(c == '\''){
                i++;
                while(input[i] != '\'')
                    i++;
            }
            else if(c == '\"'){
                i++;
                while(input[i] != '\"')
                    i++;
            }
            else if(c == '/'){
                if(input[i+1] == '/')
                    break;
                else if(input[i+1] == '*'){
                    flag = 0;
                    i++;
                }
            }

            else if(is_brace(c) == 1){
                save[count].line = lin;
                save[count].shape = c;
                count++;


            }

        }
        memset(input,0,sizeof(input));
        lin++;
    }


    int point = 0;flag = 0;
    for(int i=0;i<count;i++){
        stock[point] = save[i];
        if(point > 0){
            if(stock[point].shape == ')' && stock[point-1].shape == '(')
            {
                stock[point].line = stock[point-1].line = 0;
                stock[point].shape = stock[point-1].shape = 0;
                point -= 2;
            }
            if(stock[point].shape == '}' && stock[point-1].shape == '{')
            {
                stock[point].line = stock[point-1].line = 0;
                stock[point].shape = stock[point-1].shape = 0;
                point -= 2;
            }
            if(stock[point].shape == '{' && stock[point-1].shape == '(')
            {
                printf("without maching \'%c\' at line %d",stock[point-1].shape,stock[point-1].line);
                flag =1;
                break;
            }
            if(stock[point].shape == ')' && stock[point-1].shape != '(')
            {
                printf("without maching \'%c\' at line %d",stock[point].shape,stock[point].line);
                flag = 1;
                break;
            }
            if(stock[point].shape == '}' && stock[point-1].shape != '{')
            {
                printf("without maching \'%c\' at line %d",stock[point].shape,stock[point].line);
                flag = 1;
                break;
            }
        }

        point++;
    }
    if(stock[0].line != 0 && flag == 0)
    {
        printf("without maching \'%c\' at line %d",stock[0].shape,stock[0].line);
    }
    else if(stock[0].line == 0 && flag == 0){
        for(int i=0;i<count;i++){
            printf("%c",save[i].shape);
        }
    }

    fclose(in);
    return 0;
}