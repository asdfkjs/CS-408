#include <stdio.h>

#define MaxSize 50
typedef int ElemType;//让顺序表存储其他类型元素时，可以快速完成代码修改
typedef struct{
    ElemType data[MaxSize];
    int length;//顺序表长度
}SqList;
//顺序表的插入，因为L会改变，因此我们这里要用引用,i是插入的位置
bool ListInsert(SqList &L,int i,ElemType element)
{
    //判断i是否合法
    if(i<1 || i>L.length+1)
    {
        return false;
    }
    //如果存储空间满了，不能插入
    if(L.length==MaxSize)
    {
        return false;//未插入返回false
    }
    //把后面的元素依次往后移动，空出位置，来放要插入的元素
    for(int j=L.length;j>=i;j--)
    {
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=element;//放入要插入的元素
    L.length++;//顺序表长度要加1
    return true;//插入成功返回true
}

//打印顺序表
void PrintList(SqList L)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        printf("%3d",L.data[i]);//为了打印到同一行
    }
    printf("\n");
}

//顺序表的初始化及插入操作实战
int main() {
    SqList L;//定义一个顺序表，变量L
    bool ret;//ret用来装函数的返回值
    L.data[0]=1;//放置元素
    L.data[1]=2;
    L.data[2]=3;
    L.length=3;//设置长度
    ret=ListInsert(L,2,60);
    if(ret)
    {
        printf("insert sqlist success\n");
        PrintList(L);
    }else{
        printf("insert sqlist failed\n");
    }
    return 0;
}
