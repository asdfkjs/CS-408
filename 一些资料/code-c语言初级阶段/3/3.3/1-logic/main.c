#include <stdio.h>
//记住优先级目的，不能够加多余的括号
int main() {
    int year,i,j=6;
    while(scanf("%d",&year))
    {
        if(year%4==0&&year%100!=0 || year%400==0)
        {
            printf("%d is leap year\n",year);
        }else{
            printf("%d is not leap year\n",year);
        }
    }
    i=!!j;
    printf("i value=%d\n",i);
    return 0;
}
