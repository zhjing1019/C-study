/*
 * 读入数据string[ ]，然后读入一个短字符串。要求查找string[ ]中和短字符串的所有匹配，
 * 输出行号、匹配字符串。匹配时不区分大小写，并且可以有一个用中括号表示的模式匹配。
 * 如“aa[123]bb”，就是说aa1bb、aa2bb、aa3bb都算匹配。
 * */
#include <stdio.h>
#include <string.h>

int main() {
    char str[1000][10];
    char pattern[30];
    int n; char* p1; char* p2; int flag ;
    int copy[1000]; int count ;
    while (scanf("%d", &n)!=EOF) {
        count = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", str[i]);
        }
        scanf("%s", pattern);
        for (int j = 0; j < n; j++) {
            p1 = str[j]; p2 = pattern; flag = 1;
            while (*p1 != '\0' && *p2 != '\0' && flag == 1) {
                if (*p2 == '[') {
                    while (*(++p2) != ']') {
                        if ((*p1 >= 65 && *p1 <= 90 ? *p1 + 32 : *p1) == (*p2 >= 65 && *p2 <= 90 ? *p2 + 32 : *p2))
                            break;
                    }
                    if (*p2 == ']') {
                        flag = 0; break;
                    }
                    else {
                        while (*p2++ != ']');
                        p1++;
                        continue;
                    }
                }
                if ((*p1 >= 65 && *p1 <= 90 ? *p1 + 32 : *p1) == (*p2 >= 65 && *p2 <= 90 ? *p2 + 32 : *p2) && *p1 && *p2) {
                    p1++; p2++;
                }
                else {
                    flag = 0; break;
                }
            }
            if (*p2 == '\0' && *p1 == '\0' && flag == 1) {
                copy[count++] = j;
            }
        }
        for (int i = 0; i < count; i++)
            printf("%d %s\n", copy[i] + 1, str[copy[i]]);
    }
    return 0;
}