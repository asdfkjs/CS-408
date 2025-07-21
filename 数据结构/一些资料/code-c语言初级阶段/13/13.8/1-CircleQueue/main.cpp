#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode* next;//指向下一个结点
}LNode, * LinkList;


void EnQueue(LinkList front, LinkList& rear, ElemType val)
{
    LinkList pnew;
    if (rear->next == front)//判断队列是不是满了
    {
        //队列满，申请一个结点的空间，放入队列
        pnew= (LinkList)malloc(sizeof(LNode));
        rear->data = val;//把入队元素放入rear指向结点
        rear->next = pnew;//放了一个结点，其相当于做了分割
        pnew->next = front;
        rear = pnew;
    }
    else {//如果队列不满，直接放值，让rear后移一个结点
        rear->data = val;
        rear = rear->next;
    }
}

void DeQueue(LinkList& front, LinkList rear)
{
    if (front == rear)
    {
        printf("queue is empty\n");
    }
    else {
        printf("dequeue %d\n", front->data);
        front = front->next;
    }
}
//循环队列操作的总流程
void CircleQueue(LinkList& front, LinkList& rear)
{
    //队列头和队列尾都指向一个结点，这时队列既是空的，也是满的
    front = (LinkList)malloc(sizeof(LNode));
    rear = front;
    rear->next = front;//构造循环队列
    //入队
    EnQueue(front, rear, 3);
    EnQueue(front, rear, 4);
    //出队
    DeQueue(front, rear);
    DeQueue(front, rear);
    DeQueue(front, rear);
}


int main()
{
    LinkList front, rear;
    CircleQueue(front, rear);
    return 0;
}