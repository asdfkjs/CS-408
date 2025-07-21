#include <stdio.h>
//scanf一次读多种数据类型
int main() {
    int i,ret;
    float f;
    char c;
    ret=scanf("%d %c%f",&i,&c,&f);//ret是指scanf匹配成功的个数
    printf("i=%d,c=%c,f=%5.2f\n",i,c,f);
    return 0;
}
