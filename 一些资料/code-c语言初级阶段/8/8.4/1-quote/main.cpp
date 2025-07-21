#include <stdio.h>

//当你在子函数中要修改主函数中变量的值，就用引用，不需要修改，就不用
void modify_num(int &b)//形参中写&，要称为引用
{
    b=b+1;
}
//C++的引用的讲解
//在子函数内修改主函数的普通变量的值
int main() {
    int a=10;
    modify_num(a);
    printf("after modify_num a=%d\n",a);
    return 0;
}
