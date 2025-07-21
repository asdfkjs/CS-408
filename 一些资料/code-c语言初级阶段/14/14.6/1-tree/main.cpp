#include "function.h"

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
//中序遍历
void InOrder(BiTree p)
{
    if(p!=NULL)
    {
        InOrder(p->lchild);//打印左子树
        printf("%c", p->c);
        InOrder(p->rchild);//打印右子树
    }
}
//后序遍历
void PostOrder(BiTree p)
{
    if(p!=NULL)
    {
        PostOrder(p->lchild);//打印左子树
        PostOrder(p->rchild);//打印右子树
        printf("%c", p->c);
    }
}

//层序遍历
//层次遍历,层序遍历，广度优先遍历
void LevelOrder(BiTree T)
{
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;//存储出队的结点
    EnQueue(Q,T);//把根入队
    while(!IsEmpty(Q))
    {
        DeQueue(Q,p);
        putchar(p->c);//等价于printf("%c",c);
        if(p->lchild)
        {
            EnQueue(Q,p->lchild);//左孩子不为空，就入队左孩子
        }
        if(p->rchild)
        {
            EnQueue(Q,p->rchild);//右孩子不为空，就入队右孩子
        }
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
    printf("--------PreOrder----------\n");//也叫先序遍历，先打印当前结点，打印左孩子，打印右孩子
    PreOrder(tree);
    printf("\n--------InOrder------------\n");//先打印左孩子，打印父亲，打印右孩子
    InOrder(tree);
    printf("\n--------PostOrder------------\n");//先打印左孩子，打印右孩子，最后打印父亲
    PostOrder(tree);
    printf("\n--------LevelOrder------------\n");
    LevelOrder(tree);
    return 0;
}
