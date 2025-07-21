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

//快排的核心函数
//挖坑法
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
int main() {
    SSTable ST;
    ST_Init(ST,10);//初始化
//    ElemType A[10]={ 64, 94, 95, 79, 69, 84, 18, 22, 12 ,78};
    //内存copy接口，当你copy整型数组，或者浮点型时，要用memcpy，不能用strcpy，初试考memcpy概率很低
//    memcpy(ST.elem,A,sizeof(A));//这是为了降低调试难度，每次数组数据固定而设计的
    ST_print(ST);
    QuickSort(ST.elem,0,9);//注意这个位置是n-1,也就是9，因为函数里取了high位置的值
    ST_print(ST);
    return 0;
}
