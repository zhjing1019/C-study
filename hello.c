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
// #include <stdio.h>
// #include <limits.h>
// int main()
// {
//     printf("int 的数据类型： %lu \n", sizeof(int) );
//     return 0;
// }

/*
* 浮点类型
* float : 4字节
* double: 8字节
* long double：16字节
* %E 为以指数形式输出单、双精度实数
*/
// #include <stdio.h>
// #include <float.h>
// int main()
// {
//     printf("float 存储最大字节数：%lu \n", sizeof(float));
//     printf("float 存储最大值：%E \n", FLT_MAX);
//     printf("float 存储最小值：%E \n", FLT_MIN);
//     printf("float 存储精度：%E \n", FLT_DIG);
//     return 0;
// }