#include <stdio.h>
//课时8的作业1 练习结构体
typedef struct student{
    int num;//学号
    char name[20];//姓名
    char sex;//性别
}stu;//声明一个结构体类型
int main() {
    stu s;
    scanf("%d%s %c",&s.num,s.name,&s.sex);
    printf("%d %s %c\n",s.num,s.name,s.sex);
    return 0;
}
