/*
 * 素数问题
 * 输入一个整数n(2<=n<=10000)，要求输出所有从1到这个整数之间(不包括1和这个整数)个位为1的素数，如果没有则输出-1。
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int issprime(int num) {
    if(num == 1) {
        return -1;
    }
    for(int i = 2; i <= num/2; i++) {
        if(num % i == 0) {
            return -1;
        }
    }
    return 1;
}

int loss(int num) {
    int i = 1, j = 0;
    while(1) {
        num %= 10;
        if(num < 10)
            break;
    }
    if(num == 1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num, sum = 0, A[10001];
    while(scanf("%d", &num) != EOF) {
        for(int i = 11; i < num; i++) {
            if(issprime(i)) {
                if(loss(i)) {
                    A[sum] = i;
                    sum++;
                }
            }
        }
        for(int h = 0; h < sum - 1; h++) {
            printf("%d ", A[h]);
        }
        printf("%d\n", A[sum-1]);
        if(sum == 0) printf("-1\n");
        sum = 0;
    }
    return 0;
}