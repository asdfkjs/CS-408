#include <stdio.h>
#include <stdlib.h>


typedef int KeyType;
typedef struct BSTNode{
	KeyType key;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BiTree;

// 王道书上的递归写法，代码简单，但是理解有难度
int BST_Insert1(BiTree &T,KeyType k)
{
    if(NULL==T)
    {	//为新节点申请空间，第一个结点作为树根，后面递归再进入的不是树根，是为叶子结点
        T=(BiTree)malloc(sizeof(BSTNode));
        T->key=k;
        T->lchild=T->rchild=NULL;
        return 1;//代表插入成功
    }
    else if(k==T->key)
        return 0;//发现相同元素，就不插入
    else if(k<T->key)//如果要插入的结点，小于当前结点
        //函数调用结束后，左孩子和原来的父亲会关联起来，巧妙利用了引用机制
        return BST_Insert1(T->lchild,k);
    else
        return BST_Insert1(T->rchild,k);
}

//54,20,66,40,28,79,58
//非递归的创建二叉查找树
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

void InOrder(BiTree T)
{
    if(T!=NULL)
    {
        InOrder(T->lchild);
        printf("%3d",T->key);
        InOrder(T->rchild);
    }
}

BiTree BST_Search(BiTree T,KeyType k,BiTree &parent)
{
    parent=NULL;
    while(T!=NULL&&k!=T->key)
    {
        parent=T;
        if(k>T->key)
        {
            T=T->rchild;
        }else{
            T=T->lchild;
        }
    }
    return T;
}



//二叉排序树新建，中序遍历，查找
int main() {
    BiTree T=NULL;//树根
    KeyType str[7]={54,20,66,40,28,79,58};//将要进入二叉排序树的元素值
    Creat_BST(T,str,7);
    InOrder(T);//中序遍历二叉查找树是由小到大的
    printf("\n");
    BiTree search,parent;
    search=BST_Search(T,40,parent);
    if(search)
    {
        printf("find key %d\n",search->key);
    }else{
        printf("not find\n");
    }
    return 0;
}
