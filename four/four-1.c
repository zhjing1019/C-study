#include <stdio.h>
// extern "C"
// {
//     int add(int a, int b)
//     {
//         return a + b
//     }
// }
extern int g;
extern int get_min(int a, int b);

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
    printf("%d\n", g);
    printf("%d\n", get_min(1, 2));

    return 0;
}