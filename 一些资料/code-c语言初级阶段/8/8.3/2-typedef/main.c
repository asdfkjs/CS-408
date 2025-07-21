#include <stdio.h>

//stu 等价于 struct student，pstu等价于struct student*
typedef struct student{
    int num;
    char name[20];
    char sex;
}stu,*pstu;

typedef int INGETER;//特定地方使用
//typedef的使用，typedef起别名
int main() {
    stu s={1001,"wangle",'M'};
    stu *p=&s;//定义了一个结构体指针变量
    pstu p1=&s;//定义了一个结构体指针变量
    INGETER num=10;
    printf("num=%d,p->num=%d\n",num,p->num);
    return 0;
}
