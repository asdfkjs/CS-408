#include <stdio.h>
//在子函数中去改变main函数中某个变量的值

void change(int *j)//j=&i
{
    *j=*j/2;
}

int main() {
    int i;
    int *p=&i;//如果定义一个指针变量，没有初始化，就是空的藏宝图
    scanf("%d",p);
    change(p);
    printf("%d\n",*p);//输出
    return 0;
}
