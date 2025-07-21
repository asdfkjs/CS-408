#include <stdio.h>
//读取一堆整型数，统计2出现的次数
int main() {
    int element_count;//元素个数
    int arr[100];
    scanf("%d",&element_count);
    int i;
    for(i=0;i<element_count;i++)
    {
        scanf("%d",&arr[i]);//循环读取多个整型元素
    }
    //判断整型数组中2出现的次数
    int count=0;//记录2出现的次数
    for(i=0;i<element_count;i++)
    {
        if(arr[i]==2)
        {
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
