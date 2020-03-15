#include <stdio.h>
typedef enum _bool
{
    FALSE,
    TRUE,
} BOOL;
int main()
{
    int i32;
    char byte;
    short d;
    BOOL b;
    if(0 == i32)
    {
        i32++;
    } 
    else if (0 == byte)
    {
        byte++;
    }
    else if (0 == d)
    {
        d++;
    } 
    else
    {
        printf("Error");
    }
    return 0;
}