#include <stdio.h>

int main() {
    //通过调试查看元素存放顺序
    int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12 };
    printf("sizeof(a)=%d\n",sizeof(a));
    printf("a[2][3]=%d\n", a[2][3]);//最后一个元素是a[2][3]
    return 0;
}
