#include <stdio.h>
#include <string.h>
//字符串翻转，翻转后比较与原字符串是否相等
//使用增量编写法
int main() {
    char c[100];//原字符串
    char d[100]={0};//翻转后的,初始化的目的是为了d有结束符
    gets(c);
    int i,j;
    for(i=0,j= strlen(c)-1;i< strlen(c);i++,j--)
    {
        d[j]=c[i];
    }
//    puts(d);
    int result=strcmp(c,d);
    if(result>0)
    {
        printf("%d\n",1);
    } else if(result<0)
    {
        printf("%d\n",-1);
    } else{
        printf("%d\n",0);
    }
    return 0;
}
