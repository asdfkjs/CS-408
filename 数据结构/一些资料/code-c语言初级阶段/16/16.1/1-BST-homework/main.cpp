#include <stdio.h>
#include <stdlib.h>


typedef int KeyType;
typedef struct BSTNode{
    KeyType key;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BiTree;

int BST_Insert(BiTree& T,KeyType k)
{
    BiTree TreeNew= (BiTree)calloc(1,sizeof(BSTNode));//新结点申请空间
    TreeNew->key=k;//把值放入
    if(NULL==T)//树为空，新结点作为树的根
    {
        T=TreeNew;
        return 1;
    }
    BiTree p=T,parent;//p用来查找树
    while(p)
    {
        parent=p;//parent用来存p的父亲
        if(k>p->key)
        {
            p=p->rchild;
        }else if(k<p->key)
        {
            p=p->lchild;
        }else{
            return 0;//相等的元素不可以放入查找树，考研不会考相等元素放入问题
        }
    }
    //接下来要判断放到父亲的左边还是右边
    if(k>parent->key)//放到父亲右边
    {
        parent->rchild=TreeNew;
    }else{//放到父亲左边
        parent->lchild=TreeNew;
    }
    return 1;
}
//树中不放
void Creat_BST(BiTree& T,KeyType* str,int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        BST_Insert(T,str[i]);//把某一个结点放入二叉查找树
    }
}
//中序遍历
//往数组中存一个元素，下标就需要往后移动一次
//int element_pos=0;
void InOrder(BiTree T,int *arr)
{
    static int element_pos=0;//静态局部变量，只会初始化一次，和全局变量类似，只是只在函数内有效
    if(T!=NULL)
    {
        InOrder(T->lchild,arr);
        printf("%3d",T->key);
        //打印的同时把数据存储到数组中
        arr[element_pos]=T->key;//存入数组
        element_pos=element_pos+1;//每存一次，就需要让下标往后移动一下
        InOrder(T->rchild,arr);
    }
}

int BinarySearch(int* arr,KeyType key,int len)
{
    int low=0;
    int high=len-1;
    int mid;
    while(low<=high)//low<=high，可以让mid既能取到low，也能取到high
    {
        mid=(low+high)/2;
        if(key>arr[mid])//如果目标值大于中位数
        {
            low=mid+1;
        } else if(key<arr[mid])
        {
            high=mid-1;
        }else{
            return mid;
        }
    }
    return -1;
}

//15课时作业
//二叉排序树，中序遍历，二分查找
int main() {
    int arr[10];
    //读取标准输入的10个整型元素
    int i;
    for(i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    BiTree T=NULL;//给树初始化为NULL
    Creat_BST(T,arr,10);
    //中序遍历输出元素，同时存入数组arr
    InOrder(T,arr);
    printf("\n");
    int key_pos;
    key_pos=BinarySearch(arr,21,10);
    printf("%d\n",key_pos);
    return 0;
}
