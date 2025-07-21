#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
typedef struct{
    ElemType *elem;
    int TableLen;
}SSTable;

void ST_Init(SSTable &ST,int len)//申请空间，并进行随机数生成
{
    ST.TableLen=len;
    ST.elem=(ElemType *)malloc(sizeof(ElemType)*ST.TableLen);
    int i;
    srand(time(NULL));
    for(i=0;i<ST.TableLen;i++)
    {
        ST.elem[i]=rand()%100;
    }
}
void ST_print(SSTable ST)
{
    for(int i=0;i<ST.TableLen;i++)
    {
        printf("%3d",ST.elem[i]);
    }
    printf("\n");
}
void swap(ElemType &a,ElemType &b)
{
    ElemType tmp;
    tmp=a;
    a=b;
    b=tmp;
}

void SelectSort(ElemType* A,int n)
{
    int i,j,min;//min记录最小的元素的下标
    for(i=0;i<n-1;i++)
    {
        min=i;//我们认为i号元素最小
        for(j=i+1;j<n;j++)//找到从i开始到最后的序列的最小值的下标
        {
            if(A[j]<A[min])//当某个元素A[j]小于了最小元素
            {
                min=j;//将下标j赋值给min，min就记录下来了最小值的下标
            }
        }
        if(min!=i)
        {
            //遍历完毕找到最小值的位置后，与A[i]交换，这样最小值被放到了最前面
            swap(A[i],A[min]);
        }
    }
}

int main() {
    SSTable ST;
    ST_Init(ST,10);//初始化
    //下面两行为了降低调试难度，每次数组数据固定而设计的
    //ElemType A[10] = { 64, 94, 95, 79, 69, 84, 18, 22, 12 ,99 };
    //memcpy(ST.elem,A,sizeof(A));
    ST_print(ST);
    SelectSort(ST.elem,10);
    ST_print(ST);
    return 0;
}
