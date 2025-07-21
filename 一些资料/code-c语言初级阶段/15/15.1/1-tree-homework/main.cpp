#include <stdio.h>
#include <stdlib.h>

typedef char BiElemType;
typedef struct BiTNode{
    BiElemType c;//c就是书籍上的data
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

//tag结构体是辅助队列使用的
typedef struct tag{
    BiTree p;//树的某一个结点的地址值
    struct tag *pnext;
}tag_t,*ptag_t;

//前序遍历，也叫先序遍历，也是深度优先遍历
void PreOrder(BiTree p)
{
    if(p!=NULL)
    {
        printf("%c", p->c);
        PreOrder(p->lchild);//打印左子树
        PreOrder(p->rchild);//打印右子树
    }
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
        pnew->c=c;
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
    //也叫先序遍历，先打印当前结点，打印左孩子，打印右孩子
    PreOrder(tree);
    return 0;
}
