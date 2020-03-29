#include <stdio.h>
#include <malloc.h>
int checkSys()
{
    union check
    {
        int i;
        char c;
    } cc;
    cc.i = 1;
    return cc.c == 1;
}

int main() {
    printf("%d\n", checkSys());
    return 0;
}