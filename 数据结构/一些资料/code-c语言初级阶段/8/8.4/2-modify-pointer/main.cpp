#include <stdio.h>

void modify_pointer(int *&p,int *q)//引用必须和变量名紧邻
{
    p=q;
}
//子函数内修改主函数的一级指针变量
int main() {
    int *p=NULL;
    int i=10;
    int *q=&i;
    modify_pointer(p,q);
    printf("after modify_pointer *p=%d\n",*p);
    return 0;//进程已结束，退出代码为 -1073741819 ，不为0，那么代表进程异常结束
}
