#include <stdio.h>
//指针与一维数组的传递
//数组名作为实参传递给子函数时，是弱化为指针的
//练习传递与偏移
void change(char *d)
{
    *d='H';
    d[1]='E';//*(d+1)='E'与其等价
    *(d+2)='E';
}

int main() {
    char c[10]="hello";
    change(c);
    puts(c);
    return 0;
}
