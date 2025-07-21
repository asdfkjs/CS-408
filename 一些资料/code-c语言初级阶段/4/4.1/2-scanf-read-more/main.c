#include <stdio.h>
//scanf读取多种类型
//混合运算，输出格式的控制
//混合输入时每次在%c之前需要加入一个空格
int main() {
    int i;
    char j;
    float k;
    scanf("%d %c%f",&i,&j,&k);
    printf("%0.2f\n",i+j+k);
    return 0;
}
