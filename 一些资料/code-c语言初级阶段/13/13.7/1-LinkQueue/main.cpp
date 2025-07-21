#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next;
}LinkNode;
typedef struct{
	LinkNode *front,*rear;//链表头 链表尾,也可以称为队头，队尾
}LinkQueue;//先进先出

//队列的初始化，使用的是带头结点的链表来实现的
void InitQueue(LinkQueue &Q)
{
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next=NULL;
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
//通过链表来实现队列
int main() {
    LinkQueue Q;
    InitQueue(Q);//初始化队列
    EnQueue(Q,3);
    EnQueue(Q,4);
    EnQueue(Q,5);
    EnQueue(Q,6);
    EnQueue(Q,7);
    ElemType element;
    bool ret;
    ret=DeQueue(Q,element);
    if(ret)
    {
        printf("DeQueue success element= %d\n",element);
    }else{
        printf("DeQueue failed\n");
    }
    DeQueue(Q,element);
    ret=DeQueue(Q,element);
    if(ret)
    {
        printf("DeQueue success element= %d\n",element);
    }else{
        printf("DeQueue failed\n");
    }
    return 0;
}
