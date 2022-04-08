/*
 * 输入一个数组的值,求出各个值从小到大排序后的次序。
 * */
#include <stdio.h>
int sort(int A[], int n) {
    int temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(A[i] > A[j]) {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    for(int k = 0; k < n; k++) {
        printf("%d ", A[k]);
    }
    return 0;
}

int main() {
    int A[5], n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    sort(A, n);

    return 0;
}