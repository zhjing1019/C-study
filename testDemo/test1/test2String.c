/*
 * 给定一个短字符串（不含空格），再给定若干字符串，在这些字符串中删除所含有的短字符串。
 * 删除输入的短字符串(不区分大小写)并去掉空格,输出。
 * */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MaxSize 100
bool match(char *str, char *pattern){
    int i = 0, j = 0;
    char c, p;
    while(true){
        c = tolower(str[i]);
        p = tolower(pattern[j]);
        if(c == '\0' && p == '\0'){
            return true;
        }
        if(pattern[j] == '['){
            j++;
            int flag = 0;
            while(pattern[j] != ']'){
                if(c == tolower(pattern[j])){
                    flag = 1;
                }
                j++;
            }
            if(flag == 0){
                return false;
            }
        } else {
            if(c != p){
                return false;
            }
        }
        j++;
        i++;
    }
}
int main(){
    int n;
    char str[MaxSize][MaxSize];
    char pattern[MaxSize];
    int i;
    while(scanf("%d", &n) != EOF){
        for(i = 0;i < n; i++){
            scanf("%s", str[i]);
        }
        scanf("%s", pattern);
        for(int i = 0; i < n; i++){
            if(match(str[i], pattern)){
                printf("%d %s\n", i+1, str[i]);
            }
        }
    }
}