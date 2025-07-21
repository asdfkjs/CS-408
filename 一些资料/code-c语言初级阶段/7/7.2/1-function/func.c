//
// Created by 41507 on 2022/10/24.
//
#include "func.h"



//这里是函数的定义,可以调用print_star，就是嵌套调用
void print_message()
{
    printf("how do you do\n");
    print_star(6);//6是实参
}
//print_star的定义,也叫函数的实现
int print_star(int i)
{
    printf("**********************\n");
    printf("print_star %d\n",i);
    return i+3;
}