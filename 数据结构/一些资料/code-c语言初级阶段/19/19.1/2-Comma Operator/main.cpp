#include <stdio.h>

int main() {
    int i,j;
    i=10;
    j=1;
    if(i+3,j-1)//逗号表达式整体的值是最后一个表达式的值
    {
        printf("if execute\n");
    }
    //逗号表达式的常见使用场景,for的表达式1初始化多个变量用的较多
    for(i=0,j=1;i<10;i++)
    {

    }
    return 0;
}
