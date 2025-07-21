#include <stdio.h>

//if for 的汇编实战
int main()
{
    int i=5;
    int j=10;
    if (i < j)
    {
        printf("i is small\n");
    }
    for(i=0;i<5;i++)
    {
        printf("this is loop\n");
    }
    return 0;
}