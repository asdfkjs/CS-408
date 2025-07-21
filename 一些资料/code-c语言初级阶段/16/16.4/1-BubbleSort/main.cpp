#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
typedef struct{
    ElemType *elem;//存储元素的起始地址
    int TableLen;//元素个数
}SSTable;

void ST_Init(SSTable &ST,int len)
{
    ST.TableLen=len;
    ST.elem=(ElemType *)malloc(sizeof(ElemType)*ST.TableLen);//申请一块堆空间，当数组来使用
    int i;
    srand(time(NULL));//随机数生成，每一次执行代码就会得到随机的10个元素
    for(i=0;i<ST.TableLen;i++)
    {
        ST.elem[i]=rand()%100;//生成的是0-99之间
    }
}
//打印数组中的元素
void ST_print(SSTable ST)
{
    for(int i=0;i<ST.TableLen;i++)
    {
        printf("%3d",ST.elem[i]);
    }
    printf("\n");
}
//交换两个元素
void swap(int &a,int &b)
{
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
}
//往往都是用两层循环
//优先去写内层循环，再写外层循环
void BubbleSort(ElemType *A,int n)
{
    int i,j;
    bool flag;
    for(i=0;i<n-1;i++)//控制的是有序数的数目
    {
        flag= false;
        for(j=n-1;j>i;j--)//内层控制比较和交换
        {
            if(A[j-1]>A[j])
            {
                swap(A[j-1],A[j]);
                flag= true;
            }
        }
        if(false==flag)//如果一趟比较没有发生任何交换，说明数组有序，提前结束排序
        {
            return;
        }
    }
}

int main() {
    SSTable ST;
    ST_Init(ST,10);
//    ElemType A[10]={ 64, 94, 95, 79, 69, 84, 18, 22, 12 ,78};
    //内存copy接口，当你copy整型数组，或者浮点型时，要用memcpy，不能用strcpy，初试考memcpy概率很低
//    memcpy(ST.elem,A,sizeof(A));//这是为了降低调试难度，每次数组数据固定而设计的
    ST_print(ST);//随机后的结果打印
    BubbleSort(ST.elem, 10);
    ST_print(ST);//排序后再次打印
    return 0;
}
