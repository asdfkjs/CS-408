#include <stdio.h>
#include <stdlib.h>

typedef int BiElemType;
typedef struct BiTNode{
    BiElemType weight;//用字符的ASCII值作为weight值
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

//tag结构体是辅助队列使用的
typedef struct tag{
    BiTree p;//树的某一个结点的地址值
    struct tag *pnext;
}tag_t,*ptag_t;
//前序遍历，也叫先序遍历，也是深度优先遍历
//deep代表路径长度，就是有几条路径

int wpl_PreOrder(BiTree p,int deep)
{
    static int wpl=0;//静态局部变量和全局变量类似，只会初始化1次，区别是只在函数内有效
    if(p!=NULL)
    {
        //判断当为叶子结点时，将对应叶子结点weight和deep相乘，加到wpl上
        if(p->lchild==NULL && p->rchild==NULL)
        {
            wpl+=p->weight*deep;
        }
        wpl_PreOrder(p->lchild,deep+1);//递归左子树，路径长度要加1
        wpl_PreOrder(p->rchild,deep+1);//递归右子树，路径长度也要加1
    }
    return wpl;
}

int WPL(BiTree tree)
{
    return wpl_PreOrder(tree,0);
}

int main() {
    BiTree pnew;//用来指向新申请的树结点
    BiTree tree=NULL;//tree是指向树根的，代表树
    char c;
    ptag_t phead=NULL,ptail=NULL,listpnew=NULL,pcur;
    //abcdefghij
    while(scanf("%c",&c))
    {
        if(c=='\n')
        {
            break;//读取到换行就结束
        }
        //calloc申请的空间大小是两个参数直接相乘，并对空间进行初始化，赋值为0
        pnew= (BiTree)calloc(1,sizeof(BiTNode));
        pnew->weight=c;
        listpnew= (ptag_t)calloc(1,sizeof(tag_t));//给队列结点申请空间
        listpnew->p=pnew;
        //如果是树的第一个结点
        if(NULL==tree)
        {
            tree=pnew;//tree指向树的根结点
            phead=listpnew;//第一个结点即是队列头，也是队列尾
            ptail=listpnew;
            pcur=listpnew;//pcur要指向要进入树的父亲元素
        }else{
            //让元素先入队列
            ptail->pnext=listpnew;
            ptail=listpnew;
            //接下来把结点放入树中
            if(NULL==pcur->p->lchild)
            {
                pcur->p->lchild=pnew;//pcur->p左孩子为空，就放入左孩子
            }else if(NULL==pcur->p->rchild)
            {
                pcur->p->rchild=pnew;//pcur->p右孩子为空，就放入右孩子
                pcur=pcur->pnext;//当前结点左右孩子都有了，pcur就指向下一个
            }
        }
    }
    printf("%d\n",WPL(tree));
    return 0;
}