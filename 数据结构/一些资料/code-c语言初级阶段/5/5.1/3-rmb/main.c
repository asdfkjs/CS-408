#include <stdio.h>
//课时4作业3
//换钞票
int main() {
    int a,b,c,d,count=0;
    for(a=1;a<=10;a++)
    {
        for(b=1;b<=20;b++)
        {
            for(c=1;c<=37;c++)
            {
                for(d=1;d<=37;d++)
                {
                    if(a+b+c+d ==40 && 10*a+5*b+2*c+d==100)
                    {
                        count++;//换法加1
                    }
                }
            }
        }
    }
    printf("%d\n",count);
    return 0;
}
