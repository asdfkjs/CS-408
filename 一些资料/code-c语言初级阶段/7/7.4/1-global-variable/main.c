#include <stdio.h>

int i=10;//i是一个全局变量,不建议使用
void print(int a)//形参看成一个局部变量
{
    printf("I am print i=%d\n",i);
}

int main() {
    {
        int j=5;
    }//局部变量只在离自己最近的大括号内有效
    int i=5;
    printf("main i=%d\n",i);
    for(int k=0;k<-1;)
    {

    }
//    printf("k=%d\n",k);for循环括号内定义的变量，循环体外不可用
    print(3);
    return 0;
}
