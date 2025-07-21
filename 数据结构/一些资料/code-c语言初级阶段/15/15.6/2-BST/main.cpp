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

//这个书上没有二叉排序树删除代码--考大题没那么高
void DeleteNode(BiTree &root,KeyType x)
{
    if(NULL==root)
    {
        return;
    }
    if(root->key>x)//当前结点大于要删除的结点，往左子树找
    {
        DeleteNode(root->lchild,x);
    }else if(root->key<x)//当前结点小于要删除的结点，往右子树找
    {
        DeleteNode(root->rchild,x);
    }else{//找到了要删除的结点
        if(root->lchild==NULL)//左子树为空，右子树直接顶上去
        {
            BiTree tempNode=root;
            root=root->rchild;
            free(tempNode);
        }else if(root->rchild==NULL)//右子树为空，左子树直接顶上去
        {
            BiTree tempNode=root;
            root=root->lchild;
            free(tempNode);
        }else{//两边都不为空
            //一般的删除策略是左子树的最大数据 或 右子树的最小数据
            // 代替要删除的节点(这里采用查找左子树最大数据来代替，最大数据是左子树的最右结点)
            BiTree tempNode=root->lchild;
            BiTree parent=root->lchild;
            while(tempNode->rchild!=NULL)
            {
                parent=tempNode;//每次tempNode往右走的时候，先保存一下当前位置
                tempNode=tempNode->rchild;
            }
            root->key=tempNode->key;//把tempNode对应的值替换到要删除的值的位置上
            if(parent!=tempNode)
            {
                //把tempNode左子树，作为parent的右子树
                parent->rchild = tempNode->lchild;
            }
            else//当左子树没有右侧结点时
            {
                //把tempNode左子树，作为root的左子树即可
                root->lchild=tempNode->lchild;
            }
            free(tempNode);
        }
    }
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
    DeleteNode(T,54);//删除某个结点
    InOrder(T);
    printf("\n");
    return 0;
}
