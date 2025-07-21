#include <stdio.h>

int add(int a, int b) {
    int ret;
    ret = a + b;
    return ret;
}
//指针的间接访问，函数调用，返回值
int main() {
    int a, b, ret;
    int *p;
    a = 5;
    p = &a;
    b = *p + 2;
    ret = add(a, b);
    printf("add result=%d\n", ret);
    return 0;
}