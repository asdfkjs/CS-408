#include <stdio.h>
//switch 日期升级
int main()
{
    int mon,year;
    while(scanf("%d%d",&year,&mon))
    {
        switch (mon)
        {
            case 2:printf("mon=%d is %d days\n",mon,28+(year%4==0&&year%100!=0||
                                                        year%400==0));break;
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:printf("mon=%d is 31days\n",mon);break;
            case 4:
            case 6:
            case 9:
            case 11:printf("mon=%d is 30days\n",mon);break;
            default:
                printf("error mon\n");
        }
    }
    return 0;
}