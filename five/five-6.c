#include <stdio.h>

#define DIM(a) (sizeof(a)/sizeof(*a))

int main()
{
    int a[] = {2, 3, 5, 7, 2, 2, 2, 5, 3, 7, 1, 1, 1};
    int find = 0;
    int i = 0;
    for(i = 0; i <DIM(a); i++)
    {
        find = find ^ a[i];
    }
    printf("find=%d\n", find);
    return 0;
}