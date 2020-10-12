#include <stdio.h>
struct st 
{
	int x;
	int *y;
	
}*p;
int dt[4] = {10, 20, 30, 40};
struct st aa[4] = {50, &dt[0], 60, &dt[0], 60, &dt[0], 60, &dt[0]};

int main()
{
	p = aa;
	//printf("%d \n",*p -> x);
	//printf("%d \n",*p -> y);
	printf("%d \n",p -> x);
	printf("%d \n",++p -> x);
	printf("%d \n",(++p) -> x);
	printf("%d \n",++(*p -> y));
   
   return 0;
}