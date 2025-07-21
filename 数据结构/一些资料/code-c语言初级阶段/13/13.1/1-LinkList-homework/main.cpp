#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;//数据域
    struct LNode *next;
}LNode,*LinkList;

//尾插法新建链表
void list_tail_insert(LNode* &L)
{
    L= (LinkList)malloc(sizeof(LNode));//申请头结点空间，头指针指向头结点
    L->next=NULL;
    ElemType x;
    scanf("%d",&x);
    LNode *s,*r=L;//s是用来指向申请的新结点，r始终指向链表尾部
    while(x!=9999)
    {
        s=(LinkList)malloc(sizeof(LNode));//为新结点申请空间
        s->data=x;
        r->next=s;//新结点给尾结点的next指针
        r=s;//r要指向新的尾部
        scanf("%d",&x);
    }
    r->next=NULL;//让尾结点的next为NULL
}

//打印链表
void PrintList(LinkList L)
{
    L = L->next;
    while (L != NULL)
    {
        printf("%3d", L->data);//打印当前结点数据
        L = L->next;//指向下一个结点
    }
    printf("\n");
}
//按位置查找
//查找第几个结点的值
LinkList GetElem(LinkList L, int i)
{
    if(i<1)
    {
        return NULL;
    }
    int j=0;
    while(L&&j<i)//查找第0个，无法进入循环，所以就返回了L
    {
        L=L->next;
        j++;
    }
    return L;
}

//往第i个位置插入
bool ListFrontInsert(LinkList L,int i,ElemType InsertVal)
{
    LinkList p= GetElem(L,i-1);
    if(NULL==p)
    {
        return false;
    }
    LinkList q=(LinkList)malloc(sizeof(LNode));//给新结点申请空间
    q->data=InsertVal;//新结点data赋值
    q->next=p->next;
    p->next=q;
    return true;
}

//删除第i个位置的元素
bool ListDelete(LinkList L, int i)
{
    LinkList p = GetElem(L, i - 1);//查找删除位置的前驱节点
    if (NULL == p)
    {
        return false;//要删除的位置不存在
    }
    LinkList q = p->next;
    if (NULL == q)
    {
        return false;//要删除的位置不存在
    }
    p->next = q->next;//断链
    free(q);//释放对应结点的空间
    q = NULL;//为了避免野指针
    return true;
}

int main() {
    LinkList L;
    list_tail_insert(L);
//    PrintList(L);
    LinkList SearchElem;
    SearchElem=GetElem(L,2);//获取第二个位置元素值
    printf("%d\n",SearchElem->data);
    ListFrontInsert(L,2,99);
    PrintList(L);
    ListDelete(L,4);
    PrintList(L);
    return 0;
}
