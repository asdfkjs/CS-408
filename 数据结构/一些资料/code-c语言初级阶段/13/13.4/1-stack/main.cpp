#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];//数组
    int top;//始终指向栈顶的一个变量
}SqStack;
//初始化栈
void InitStack(SqStack &S)
{
    S.top=-1;//初始化栈，就是S.top=-1,让栈为空
}
bool StackEmpty(SqStack S)
{
    if(-1==S.top)
    {
        return true;
    }else{
        return false;
    }
}
//入栈
bool Push(SqStack &S,ElemType x)
{
    //判断栈是否满了
    if(S.top==MaxSize-1)
    {
        return false;
    }
    S.data[++S.top]=x;//等价于S.top=S.top+1;   S.data[S.top]=x;
    return true;
}
//获取栈顶元素
bool GetTop(SqStack S,ElemType &m)
{
    if(StackEmpty(S))
    {
        return false;
    }
    m=S.data[S.top];//拿栈顶元素
    return true;
}
//弹栈
bool Pop(SqStack &S,ElemType &m)
{
    if(StackEmpty(S))
    {
        return false;
    }
    m=S.data[S.top--];//出栈 后减减等价于 先m=S.data[S.top];S.top=S.top-1;
    return true;
}
int main() {
    SqStack S;
    InitStack(S);
    bool flag;
    flag=StackEmpty(S);
    if(flag)
    {
        printf("stack is empty\n");
    }
    Push(S,3);//入栈元素3
    Push(S,4);//入栈元素4
    Push(S,5);
    ElemType m;
    flag=GetTop(S,m);//获取栈顶元素
    if(flag)
    {
        printf("get top %d\n",m);
    }
    flag=Pop(S,m);//弹出栈顶元素
    if(flag)
    {
        printf("pop element %d\n",m);
    }
    return 0;
}
