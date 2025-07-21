#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct BiTree{
    ElemType data;
    struct BiTree *lChild;
    struct BiTree *rChild;
}*tree;
typedef struct LNode{
    tree p;
    struct LNode *next;
}*LinkList;
typedef BiTree* ElemKey;
typedef struct LinkNode{
    ElemKey data;
    struct LinkNode *next;
}LinkNode;
typedef struct{
    LinkNode *front,*rear;//链表头 链表尾,也可以称为队头，队尾
}LinkQueue;//先进先出
void InitQueue(LinkQueue &q){
    q.front=q.rear=(LinkNode*) malloc(sizeof (LinkNode));
    q.front->next=NULL;
}
void Enqueue(LinkQueue &l,ElemKey root){
    LinkNode* pNew;
    pNew= (LinkNode*)calloc(1,sizeof(LinkQueue) );
    pNew->data=root;
    l.rear->next=pNew;
    l.rear=pNew;
}
void outQueue(LinkQueue &l,ElemKey &x){
    if (l.rear==l.front)
        return;
    LinkNode* q;
    q=l.front->next;
    x=q->data;
    l.front->next= q->next;
    if (q==l.rear)
        l.front=l.rear;
    free(q);
}

void levelOrder(tree root){
    LinkQueue q;
    ElemKey x;
    InitQueue(q);
    Enqueue(q,root);
    while (q.rear!=q.front){
        outQueue(q,x);
        printf("%3c",x->data);
        fflush(stdout);
        if (x->lChild!=NULL){
            Enqueue(q,x->lChild);
        }
        if (x->rChild!=NULL){
            Enqueue(q,x->rChild);
        }
    }
    printf("\n");
}
int main() {//abcdef
    setbuf(stdout,NULL);
    tree root,pNTree;
    root=NULL;
    ElemType x;
    LinkList pDad,pSon,pNew;
    while (scanf("%c",&x)){
        if (x=='\n')
            break;
        pNTree=(tree) calloc(1,sizeof (BiTree));
        pNew=(LinkList) calloc(1,sizeof (LNode));
        pNTree->data=x;
        pNew->p=pNTree;//辅助指针的存放tree的地址
        if (root==NULL){//如果树根为空
            root=pNTree;//新树为树根
            pSon=pNew;
            pDad=pNew;
        }else{
            pSon->next=pNew;
            pSon=pNew;
            if (pDad->p->lChild==NULL){
                pDad->p->lChild=pNTree;
            } else{
                pDad->p->rChild=pNTree;
                pDad=pDad->next;
            }
        }
    }
    levelOrder(root);
    return 0;
}
