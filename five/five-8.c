#include <stdio.h>
fun (int n, int *s)
{
	int f1, f2;
	if(n == 1 || n == 2) *s = 1;
	else {
		fun(n-1, &f1);
		fun(n-2, &f2);
	}
}

int main()
{
	int x;
	fun(6, &x);
	printf("%d \n",x);
   
   return 0;
}