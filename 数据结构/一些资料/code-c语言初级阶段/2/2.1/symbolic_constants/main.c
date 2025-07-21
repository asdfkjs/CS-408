#include <stdio.h>
//符号常量
#define PI 3+2
int main() {
    int i=PI*2;//i就是一个整型变量
    printf("i=%d\n",i);//printf是用来输出的
    printf("i size=%d\n",sizeof(i));//sizeof可以用来计算某个变量的空间大小
    return 0;
}
