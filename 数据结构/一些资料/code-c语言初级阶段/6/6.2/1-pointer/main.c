#include <stdio.h>

int main() {
    int i=5;
    //定义了一个指针变量，i_pointer就是指针变量名
    //指针变量的初始化是某个变量取地址来赋值，不能随机写个数
    int *i_pointer;
    i_pointer=&i;
    printf("i=%d\n",i);//直接访问
    printf("*i_pointer=%d\n",*i_pointer);//间接访问
    return 0;
}
