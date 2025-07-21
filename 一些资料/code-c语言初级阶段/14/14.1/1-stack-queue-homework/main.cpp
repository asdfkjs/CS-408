#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];//数组
    int top;//始终指向栈顶的一个变量
}SqStack;

//下面是循环队列的结构体类型
typedef struct{
    ElemType data[MaxSize];//数组,存储MaxSize-1个元素
    int front,rear;//队列头 队列尾
}SqQueue;

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

//循环队列的函数
void InitQueue(SqQueue &Q)
{
    Q.front=Q.rear=0;//初始化循环队列，就是让头和尾都指向零号
}
//判断循环队列是否为空
bool isEmpty(SqQueue Q)
{
    return Q.rear==Q.front;
}
//入队
bool EnQueue(SqQueue &Q,ElemType x)
{
    if((Q.rear+1)%MaxSize==Q.front)//判断循环队列是否满了，满了就不能入队了
    {
        return false;
    }
    Q.data[Q.rear]=x;//放入元素
    Q.rear=(Q.rear+1)%MaxSize;//rear要加1，如果大于数组最大下标，回到开头
    return true;
}
//出队
bool DeQueue(SqQueue &Q,ElemType &x)
{
    if(Q.rear==Q.front)//队列为空，无法出队
    {
        return false;
    }
    x=Q.data[Q.front];//出队
    Q.front=(Q.front+1)%MaxSize;
    return true;
}

//第13节课的作业，针对栈，循环队列进行的练习
int main() {
    int element,i;
    SqStack S;
    InitStack(S);
    for(i=0;i<3;i++)
    {
        scanf("%d",&element);//读取输入的3个元素
        Push(S,element);//入栈
    }
    //把栈里的元素都弹出
    for(i=0;i<3;i++)
    {
        Pop(S,element);
        printf("%2d",element);
    }
    printf("\n");
    SqQueue Q;
    InitQueue(Q);
    bool flag;//接收是否入队成功
    for(i=0;i<5;i++)
    {
        scanf("%d",&element);//读取输入的5个元素
        flag=EnQueue(Q,element);//入队
        if(false==flag)
        {
            printf("false\n");
        }
    }
    for(i=0;i<4;i++)
    {
        DeQueue(Q,element);//出队每个元素
        printf("%2d",element);
    }
    printf("\n");
    return 0;
}
