#include <stdio.h>


#define MaxSize 50
typedef int ElemType;//让顺序表存储其他类型元素时，可以快速完成代码修改
typedef struct{
    ElemType data[MaxSize];
    int length;//顺序表长度
}SqList;

void ListInsert(SqList &L,int pos,ElemType InsertVal)
{
    //判断插入的位置是否合法
    if(pos<1 || pos>L.length+1)
    {
        return;
    }
    if (L.length >= MaxSize)
    {
        return;
    }
    int j;
    for(j=L.length;j>=pos;j--)
    {
        L.data[j]=L.data[j-1];
    }
    L.data[pos-1]=InsertVal;
    L.length++;
}

void PrintList(SqList L)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        printf("%3d",L.data[i]);
    }
    printf("\n");
}

//删除顺序表中的元素,i是要删除的元素的位置，e是为了获取被删除的元素的值
bool ListDelete(SqList &L,int i)
{
    //判断删除的元素的位置是否合法
    if(i<1 || i>L.length)
    {
        return false;//一旦走到return函数就结束了
    }
    int j;
    for(j=i;j<L.length;j++)//往前移动元素
    {
        L.data[j-1]=L.data[j];
    }
    L.length--;//顺序表长度减1
    return true;
}

//课时10作业
//不要直接复制上课老师写的代码，可以复制自己独立写的代码
int main() {
    SqList L;
    L.data[0]=1;
    L.data[1]=2;
    L.data[2]=3;
    L.length=3;
    ElemType InsertVal;
    //读取要插入的元素
    scanf("%d",&InsertVal);
    ListInsert(L,2,InsertVal);//插入元素
    PrintList(L);
    //读取要删除的位置
    int DeletePos;
    bool ret;
    scanf("%d",&DeletePos);
    ret=ListDelete(L,DeletePos);
    if(ret)
    {
        PrintList(L);//删除成功后，打印顺序表
    }else{
        printf("false\n");
    }
    return 0;
}
