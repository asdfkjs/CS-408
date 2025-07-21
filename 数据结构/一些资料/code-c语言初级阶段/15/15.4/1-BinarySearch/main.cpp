#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct {
    ElemType* elem;//整型指针
    int TableLen;//存储动态数组里边元素的个数
}SSTable;


//init进行了随机数生成，折半查找我们没有使用哨兵
void ST_Init(SSTable& ST, int len)
{
    ST.TableLen = len;
    ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
    int i;
    srand(time(NULL));//随机数生成
    for (i = 0; i < ST.TableLen; i++)
    {
        ST.elem[i] = rand() % 100;
    }
}
void ST_print(SSTable ST)
{
    for (int i = 0; i < ST.TableLen; i++)
    {
        printf("%3d", ST.elem[i]);
    }
    printf("\n");
}
//实现二分查找
int BinarySearch(SSTable L, ElemType key)
{
    int low=0;
    int high=L.TableLen-1;
    int mid;
    while(low<=high)//low<=high，可以让mid既能取到low，也能取到high
    {
        mid=(low+high)/2;
        if(key>L.elem[mid])//如果目标值大于中位数
        {
            low=mid+1;
        } else if(key<L.elem[mid])
        {
            high=mid-1;
        }else{
            return mid;
        }
    }
    return -1;
}
//函数名中存储的是函数的入口地址，也是一个指针，是函数指针类型
//left指针和right指针是指向数组中的任意两个元素
//qsort规定如果left指针指向的值大于right指针指向的值，返回正值，小于，返回负值，相等返回0
int compare(const void *left, const void *right)
{
    return *(int*)left-*(int*)right;
    //return *(ElemType*)right - *(ElemType*)left;//从大到小排序
}
//二分查找
int main() {
    SSTable ST;
    ST_Init(ST,10);//初始化，随机10个元素
    ST_print(ST);
    qsort(ST.elem,ST.TableLen,sizeof(ElemType),compare);//排序
    ST_print(ST);
    ElemType key;
    printf("please input search key:\n");
    scanf("%d",&key);
    int pos=BinarySearch(ST,key);
    if(pos!=-1)
    {
        printf("find key %d\n",pos);
    }else{
        printf("not find\n");
    }
    return 0;
}
