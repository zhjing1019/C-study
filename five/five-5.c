#include <stdio.h>

#define SWAP(a,b)\
{                \
  a = a ^ b;     \
    b = a ^ b;   \
    a = a ^ b;   \
}

int main()
{
    int a = 1;
    int b = 2;
    SWAP(a, b);
    return  0;
}
