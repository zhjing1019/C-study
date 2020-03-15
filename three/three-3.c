#include <stdio.h>
void f1(int i)
{
    if( i < 6 )
    {
        printf("Failed! \n");
    }
    else if ( ( 6 <= i) && (i <= 8))
    {
        printf("Good! \n");
    } 
    else 
    {
        printf("Perfect!\n");
    }
}

void f2(char i) 
{
    switch(i)
    {
        case 'c':
            printf("c\n");
            break;
        case 'd':
            printf("d\n");
            break;
        case 'f':
            printf("f\n");
            break;
        case 'o':
            printf("o\n");
            break;
        case 'p':
            printf("p\n");
            break;  
        default:
            printf("unknow\n")  ;
            break;
    }
}

int main()
{
    f1(5);
    f2('d');
    f2('l');
    return 0;
}