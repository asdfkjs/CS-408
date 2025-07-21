#include <stdio.h>
//19课时作业2
//练习异或的特性  任何数和自己异或是0，任何数和零异或是自身，异或满足交换律
int main() {
    int i;
    int arr[5];
    for(i=0;i<5;i++)//读取5个整型数
    {
        scanf("%d",&arr[i]);
    }
    int result=0;
    for(i=0;i<5;i++)//把数组中的每个元素遍历进行异或
    {
        result^=arr[i];
    }
    printf("%d\n",result);
    return 0;
}
