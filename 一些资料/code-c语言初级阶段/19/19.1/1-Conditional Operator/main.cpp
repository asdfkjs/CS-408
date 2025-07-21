#include <stdio.h>

int main() {
    int a,b,max;
    while(scanf("%d%d",&a,&b))
    {
        max=a>b?a:b;//条件运算符的优先级高于赋值运算符
        //a和b中较大的那个数是？
        printf("max=%d\n",max);
    }
    return 0;
}
