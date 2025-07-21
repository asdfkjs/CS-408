#include <stdio.h>
//switch 日期例子
int main()
{
    int year,mon;
    while(scanf("%d%d",&year,&mon))
    {
        switch (mon)
        {
            case 2:printf("mon=%d is %d days\n",mon,28+(year%4==0&&year%100!=0||
                                                        year%400==0));break;
            case 1:printf("mon=%d is 31days\n",mon);break;
            case 3:printf("mon=%d is 31days\n",mon);break;
            case 5:printf("mon=%d is 31days\n",mon);break;
            case 7:printf("mon=%d is 31days\n",mon);break;
            case 8:printf("mon=%d is 31days\n",mon);break;
            case 10:printf("mon=%d is 31days\n",mon);break;
            case 12:printf("mon=%d is 31days\n",mon);break;
            case 4:printf("mon=%d is 30days\n",mon);break;
            case 6:printf("mon=%d is 30days\n",mon);break;
            case 9:printf("mon=%d is 30days\n",mon);break;
            case 11:printf("mon=%d is 30days\n",mon);break;
            default:
                printf("error mon\n");
        }
    }
    return 0;
}