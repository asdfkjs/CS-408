#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct LNode{
    element data;
    struct LNode *next;
}LNode,*LinkList;
LinkList LinkListBulid(LinkList &L){
    L=(LinkList)malloc(sizeof(LNode));
    LinkList s;
    L->next=NULL;
    for(int i=10;i>=1;i--){
        s=(LinkList)malloc(sizeof(LNode));
        s->data=i;
        s->next=L->next;
        L->next=s;}
    return L;
}
LinkList Rabbit(LinkList &L){
    LinkList Q;
    int j,current=1,k;
    Q=L;
    for(j=2;j<1002;j++){
        {
            for(k=1;k<=current;k++)
            {
                Q=L->next;
            }
            Q->data=0;
            Q=L;
        }
        current=(current+j)%10;
    }
    return L;
}
void PrintLinkList(LinkList L){
    L=L->next;
    while(L!=NULL){
        if(L->data){
            printf("%3d",L->data);}
        L=L->next;}
}

int main(){
    LinkList L;
    LinkListBulid(L);
    Rabbit(L);
    printf("possible\n");
    PrintLinkList(L);
    printf("\n");
    return 0;
}
