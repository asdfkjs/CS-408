#include <stdio.h>
//for 循环实现从1加到100
int main() {
    int i,total;
    for(i=1,total=0;i<=100;i++)//for小括号后不要加分号
    {
        total+=i;
    }
    printf("total=%d\n",total);
    return 0;
}
