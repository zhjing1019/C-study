/*
 * 给定闭区间[a,b] ,要求输出 连续的素数的等差序列,三个以上才算是序列，例如 [100,200] 会输出 151 157 163
 * 再例如输入[1,100]  会有两个等差序列，3 5 7 和47 53 59。输出样式行末的空格保留。
 * */
#include <stdio.h>
int isPrime(int num) {
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

int main() {
    int a, b, i;
    scanf("%d %d", &a, &b);
    int arr[10001];
    int top = 0;
    for(i = a; i <= b; i++) {
        if(isPrime == 1) {
            arr[top++] = 1;
        }
    }
    for(i = 0; i < top; i++) {
        if(arr[i + 1] * 2 == arr[i]+arr[i + 2]) {
            int c = arr[i+1]-arr[i];
            int max=i+2;
            while((max < top) && (arr[max] - arr[max-1] == c)){
                max++;
            }
            max--;
            int j;
            for(j = i;j <= max;j++){
                printf("%d ",arr[j]);
            }
            printf("\n");
            i = max;
        }
    }
}