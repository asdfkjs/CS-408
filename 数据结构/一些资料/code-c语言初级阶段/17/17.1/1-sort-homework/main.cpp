#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
typedef struct{
    ElemType *elem;//存储元素的起始地址
    int TableLen;//元素个数
}SSTable;

//用于申请空间，初始化 ST.TableLen
void ST_Init(SSTable &ST,int len)
{
    ST.TableLen=len;
    ST.elem=(ElemType *)malloc(sizeof(ElemType)*ST.TableLen);//申请一块堆空间，当数组来使用
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

int partition(ElemType *A,int low,int high)
{
    ElemType pivot=A[low];//拿最左边的作为分割值，并存储下来
    while(low<high)
    {
        while(low<high&&A[high]>=pivot)//从后往前遍历，找到一个比分割值小的
            high--;
        A[low]=A[high];//把比分隔值小的那个元素，放到A[low]
        while(low<high&&A[low]<=pivot)//从前往后遍历，找到一个比分割值大的
            low++;
        A[high]=A[low];//把比分隔值大的那个元素，放到A[high],因为刚才high位置的元素已经放到了low位置
    }
    A[low]=pivot;//把分割值放到中间位置，因为左边刚好都比它小，右边都比它大
    return low;//返回分隔值所在的下标
}

void QuickSort(ElemType *A,int low,int high)
{
    if(low<high)
    {
        int pivot_pos=partition(A,low,high);//pivot用来存分割值的位置
        QuickSort(A,low,pivot_pos-1);//前一半继续递归排好
        QuickSort(A,pivot_pos+1,high);
    }
}

void InsertSort(ElemType *A,int n)
{
    int i,j,insertVal;
    for(i=1;i<n;i++)//外层控制要插入的数
    {
        insertVal=A[i];//保存要插入的数
        //内层控制比较,j要大于等于0，同时arr[j]大于insertval时，arr[j]位置元素往后覆盖
        for(j=i-1;j>=0&&A[j]>insertVal;j--)
        {
            A[j+1]=A[j];
        }
        A[j+1]=insertVal;//把要插入的元素放到对应的位置
    }

}

//16课时OJ作业
int main() {
    SSTable ST;
    ST_Init(ST,10);
    ElemType A[10];
    //从标准输入读取10个整型元素
    int i;
    for(i=0;i<10;i++)
    {
        scanf("%d",&A[i]);
    }
    //内存copy接口，当你copy整型数组，或者浮点型时，要用memcpy，不能用strcpy，初试考memcpy概率很低
    memcpy(ST.elem,A,sizeof(A));//这是为了降低调试难度，每次数组数据固定而设计的
//    ST_print(ST);//方便调试，显示一下读取了标准输入后的，数组内数据
    BubbleSort(ST.elem, 10);
    ST_print(ST);//排序后再次打印
    memcpy(ST.elem,A,sizeof(A));//为快速排序准备无序的数据
    QuickSort(ST.elem,0,9);
    ST_print(ST);//排序后再次打印
    memcpy(ST.elem,A,sizeof(A));//为插入排序准备无序的数据
    InsertSort(ST.elem,10);
    ST_print(ST);
    return 0;
}
