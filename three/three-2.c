#include <stdio.h>
#define E 0.0000001

int main()
{
    float f = 5.0;
    if( 5 - E <= f && f <= 5 + E)
    {
        printf("ok\n");
    } else {
        printf("error\n");
    }
    return 0;
}