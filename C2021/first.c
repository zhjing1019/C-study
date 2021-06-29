// 要用到输入输出函数！
# include <stdio.h>
// hello world C program
int main()
{
  printf("hello world C program \n");

  // 求俩个数之和
  int a, b, sum;
  a = 123;
  b = 321;
  sum = a + b;
  printf("sum is %d\n", sum);  //输出格式字符串，%d是指定输出格式

  // // 求俩个整数中的较大者
  // int max(int x, int y);
  // int c, d, e;
  // scanf("%d, %d", &c, &d);
  // e = max(c, d);
  // printf("max is %d", e);

  // 求5的阶乘 5!
  int t, i;
  t = 1;
  i = 2;
  while (i <= 5)
  {
    t *= i;
    i++;
  }
  printf("%d\n", t);

  return 0;
}

//求俩个整数中较大者，max函数
int max(int x, int y)
{
  int z;
  if(x > y) z = x;
  else z = y;
  return z;
}

