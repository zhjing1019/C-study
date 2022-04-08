/*
 * 扩展字符A
 * 从键盘输入包含扩展符'-'的字符串，将其扩展为等价
 * 的完整字符，例如将a-d扩展为abcd，并输出扩展后的
 * 字符串。
 *
 * 只处理[a-z]、[A-Z]、[0-9]范围内的字符扩展，
 * 即只有当扩展符前后的字符同时是小写字母、大写字
 * 母或数字，并且扩展符后的字符大于扩展符前的字符
 * 时才进行扩展，其它情况不进行扩展，原样输出。例
 * 如：a-R、D-e、0-b、4-B等字符串都不进行扩展。
 * */
#include <stdio.h>

int main () {
    char A[100];
    gets(A);
    char *p;
    p = A;
    while(*p != '\0') {
        if(*p != '-') {
            printf("%c", *p);
            p++;
        } else {
            char a = *(p - 1);
            char b = *(p + 1);
            if(a < b) {
                while((a + 1 ) < b) {
                    printf("%c", ++a);
                }
            } else {
                printf("%c", *p);
            }

            p++;
        }
    }
    return 0;
}
