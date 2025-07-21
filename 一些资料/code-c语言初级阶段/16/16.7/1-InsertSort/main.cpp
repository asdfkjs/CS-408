#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct{
    ElemType *elem;//整型指针
    int TableLen;
}SSTable;

void ST_Init(SSTable &ST,int len)
{
    ST.TableLen=len;//申请10个元素的空间
    ST.elem=(ElemType *)malloc(sizeof(ElemType)*ST.TableLen);
    int i;
    srand(time(NULL));
    for(i=0;i<ST.TableLen;i++)
    {
        ST.elem[i]=rand()%100;//随机了10个数
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
int main() {
    SSTable ST;
    ST_Init(ST,10);//申请10个元素空间
    ST_print(ST);//排序前打印
    InsertSort(ST.elem,10);
    ST_print(ST);//排序后再次打印
    return 0;
}
