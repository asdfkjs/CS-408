#include <stdio.h>
//强制类型转换
int main() {
    int i=5;
    float f=i/2;//这里做的是整型运算，因为左右操作数都是整型
    float k=(float)i/2;
    printf("%f\n",f);
    printf("%f\n",k);
    return 0;
}
