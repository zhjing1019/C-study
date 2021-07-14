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

  //给定一个大写字母，要求用小写字母输出
  char c1, c2;
  c1 = 'A';
  c2 = c1 + 32;
  printf("%c\n", c1);
  printf("%c\n", c2);

  // 输入一个大于3的整数n，判定他是否为素数
  int n, i;
  printf("please enter a integer number, n=?");
  scanf("%d", &n);
  for(i = 2;i < n-1; i++) {
    if(n%i == 0) break;
    if(i < n) printf("%d is not prime number. \n", n);
    else printf("%d is a prime number.\n", n);
    return 0;
  }

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

