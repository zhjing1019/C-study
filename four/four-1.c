#include <stdio.h>

void* my_memset (void* p, char v, int size)
{
    void* ret = p;
    char* dest = (char*) p;
    int i = 0;
    for (i = 0; i<size; i++)
    {
        dest[i] = v;
    }
    return ret;
}


int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]);
    }
    my_memset(a, 0, sizeof(a));
    for(int i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}