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
		ST.elem[i]=rand();
	}
}
void ST_print(SSTable ST)
{
	for(int i=0;i<10;i++)
	{
		printf("%3d\n",ST.elem[i]);
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

//调整子树
void AdjustDown(ElemType A[], int k, int len)
{
	int dad = k;
	int son = 2 * dad + 1; //左孩子下标
	while (son<=len)
	{
		if (son + 1 <= len && A[son] < A[son + 1])//看下有没有右孩子，比较左右孩子选大的
		{
			son++;
		}
		if (A[son] > A[dad])//比较孩子和父亲，如果孩子大于父亲，那么进行交换
		{
			swap(A[son], A[dad]);
			dad = son;//孩子重新作为父亲，判断下一颗子树是否符合大根堆
			son = 2 * dad + 1;
		}
		else {
			break;
		}
	}
}
void HeapSort(ElemType A[], int len)
{
	int i;
	//先对前10个元素建立大根堆
	for (i = len/2; i >= 0; i--)
	{
		AdjustDown(A, i, len);
	}
	//比较剩余的A[10]到A[99999]元素，小于堆顶，就放入A[0],继续调整10个元素为大根堆
	for (i = 10; i < 100000; i++)
	{
		if (A[i] < A[0])
		{
			A[0] = A[i];
			AdjustDown(A, 0, 9);//继续调整为大根堆
		}
	}
}

//《王道C督学营》课程
//2022年42题真题实战
int main()
{
	SSTable ST;
	ST_Init(ST,100000);//初始化
	HeapSort(ST.elem,9);
	ST_print(ST);
	return 0;
}