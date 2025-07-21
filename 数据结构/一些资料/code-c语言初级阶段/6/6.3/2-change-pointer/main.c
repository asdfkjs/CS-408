#include <stdio.h>
//在子函数内去改变主函数中某个变量的值
void change(int *j)//j是形参
{
    *j=5;//*j等价于变量i，只是间接访问
}

int main() {
    int i=10;
    printf("before change i=%d\n",i);
    change(&i);//C语言的函数调用是值传递，实参赋值给形参，j=&i
    printf("after change i=%d\n",i);
    return 0;
}
