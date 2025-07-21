#include <stdio.h>

//练习if与else
int main() {
    int i;
    while(scanf("%d",&i))
    {
        if(i>0)//if下面加一个大括号
        {
            printf("i is bigger than 0\n");
        }else{
            printf("i is not bigger than 0\n");
        }
    }

    return 0;
}
