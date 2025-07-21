#include <stdio.h>

//关系运算符，优先级小于算术运算符
int main() {
    int a;
    while(scanf("%d",&a))
    {
        if(3<a && a<10)//a大于3同时a小于10要这样写
        {
            printf("a is between 3 and 10\n");
        }else{
            printf("a is not between 3 and 10\n");
        }
    }
    return 0;
}
