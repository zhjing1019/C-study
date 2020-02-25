/*
* hello world
*/
// #include <stdio.h>
// int main()
// {
//     printf("hello world!");
//     return 0;
// }

/*
* sizeof %lu \n
* %lu 为 32 位无符号整数
*/
#include <stdio.h>
#include <limits.h>
int main()
{
    printf("int 的数据类型： %lu \n", sizeof(int) );
    return 0;
}