#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
typedef struct{
    ElemType *elem;
    int TableLen;
}SSTable;

void ST_Init(SSTable &ST,int len)//申请空间
{
    ST.TableLen=len;
    ST.elem=(ElemType *)malloc(sizeof(ElemType)*ST.TableLen);
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

//把某个子树调整为大根堆
void AdjustDown1(ElemType A[],int k,int len)
{
    int dad=k;//父亲的下标
    int son=2*dad+1;//左孩子的下标
    while(son<len)
    {
        if(son+1<len&&A[son]<A[son+1])//如果左孩子小于右孩子
        {
            son++;//拿右孩子
        }
        if(A[son]>A[dad])//如果孩子大于父亲
        {
            swap(A[son],A[dad]);//交换
            dad=son;//son从新作为dad，去判断下面的子树是否符合大根堆
            son=2*dad+1;
        }else{
            break;
        }
    }
}

void HeapSort1(ElemType A[], int len)
{
    int i;
    //就是把堆，调整为大根堆
    for(i=len/2-1;i>=0;i--)
    {
        AdjustDown1(A,i,len);
    }
    swap(A[0],A[len-1]);//交换根部元素和最后一个元素
    for(i=len-1;i>1;i--)//i代表的是剩余的无序数的数组的长度
    {
        AdjustDown1(A,0,i);//调整剩余元素变为大根堆
        swap(A[0],A[i-1]);//交换根部元素和无序数的数组的最后一个元素
    }
}

int main() {
    SSTable ST;
    ST_Init(ST, 10);//初始化
    ElemType A[10];
    int i;
    //读取标准输入，读10个元素
    for(i=0;i<10;i++)
    {
        scanf("%d",&A[i]);
    }
    memcpy(ST.elem,A,sizeof(A));
    SelectSort(ST.elem,10);//选择排序
    ST_print(ST);
    memcpy(ST.elem,A,sizeof(A));//copy A数组中的元素
    HeapSort1(ST.elem,10);
    ST_print(ST);
    return 0;
}