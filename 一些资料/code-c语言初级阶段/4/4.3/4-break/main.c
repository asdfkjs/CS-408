#include <stdio.h>
//for 循环实现从1加到100
int main() {
    int i,total;
    for(i=1,total=0;i<=100;i++)//for小括号后不要加分号
    {
        if(total>2000)
        {
            break;//当和大于2000时，循环结束
        }
        total+=i;
    }
    printf("total=%d,i=%d\n",total,i);
    return 0;
}
