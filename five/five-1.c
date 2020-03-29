 #include <stdio.h>
 #include <malloc.h>

struct _null
{
};

int main(){
    struct _null n1;
    struct _null n2;
    printf("%d\n", sizeof(struct _null));
    printf("%d, %0X\n", sizeof(n1), &n1);
    printf("%d, %0X\n", sizeof(n1), &n1);

}