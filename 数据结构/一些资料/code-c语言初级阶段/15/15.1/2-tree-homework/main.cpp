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

//队列的结构体
typedef BiTree ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct{
    LinkNode *front,*rear;//链表头 链表尾,也可以称为队头，队尾
}LinkQueue;//先进先出
void InitQueue(LinkQueue &Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue &Q,ElemType x);
bool DeQueue(LinkQueue &Q,ElemType &x);

//队列的代码
//队列的初始化，使用的是带头结点的链表来实现的
void InitQueue(LinkQueue &Q)
{
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next=NULL;
}
//判断队列是否为空
bool IsEmpty(LinkQueue Q)
{
    return Q.rear==Q.front;
}
//入队
void EnQueue(LinkQueue &Q,ElemType x)
{
    LinkNode *pnew=(LinkNode*)malloc(sizeof(LinkNode));
    pnew->data=x;
    pnew->next=NULL;//要让next为NULL
    Q.rear->next=pnew;//尾指针的next指向pnew，因为从尾部入队
    Q.rear=pnew;//rear要指向新的尾部
}
//出队
bool DeQueue(LinkQueue &Q,ElemType &x)
{
    if(Q.rear==Q.front)//队列为空
    {
        return false;
    }
    LinkNode* q=Q.front->next;//拿到第一个结点，存入q
    x=q->data;//获取要出队的元素值
    Q.front->next=q->next;//让一个结点断链
    if(Q.rear==q)//链表只剩余一个结点时，被删除后，要改变rear
    {
        Q.rear=Q.front;
    }
    free(q);
    return true;
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
//14课时的作业2
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
    //先打印左孩子，打印父亲，打印右孩子
    InOrder(tree);
    printf("\n");
    //先打印左孩子，打印右孩子，最后打印父亲
    PostOrder(tree);
    printf("\n");
    LevelOrder(tree);
    printf("\n");
    return 0;
}
