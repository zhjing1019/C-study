#include <stdio.h>
float fun (float y)
{
	return ((int) (y*100 + 0.5) /100.0);
};

int main()
{
	float x = 8.32433, y;
	float z = 8.32533, w;
	y = fun(x);
	w = fun(z);
	printf("%f \n",y);
    printf("%f \n",w);
   return 0;
}