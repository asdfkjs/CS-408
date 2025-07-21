#include <stdio.h>
//课时4作业2
//求n的阶乘
int main() {
    int n;
    scanf("%d",&n);
    int i,result=1;
    for(i=1;i<=n;i++)
    {
        result*=i;
    }
    printf("%d\n",result);
    return 0;
}
