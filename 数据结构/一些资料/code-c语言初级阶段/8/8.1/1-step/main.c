#include <stdio.h>
//上台阶题目
int step(int n)
{
    //结束条件
    if(1==n||2==n)
    {
        return n;
    }
    return step(n-1)+ step(n-2);//递归公式
}

int main() {
    int n,result;
    scanf("%d",&n);//n输入不要太大
    result=step(n);
    printf("%d\n",result);//printf可以放各种表达式
    return 0;
}
