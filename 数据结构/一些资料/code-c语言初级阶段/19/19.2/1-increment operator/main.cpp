#include <stdio.h>

int main() {
    int i=-1,j;
//    5++;//如果打开该句，会造成编译不通
    j=i++>-1;//后++等价于j=i>-1 ; i=i+1;
    printf("i=%d,j=%d\n",i,j);
    return 0;
}
