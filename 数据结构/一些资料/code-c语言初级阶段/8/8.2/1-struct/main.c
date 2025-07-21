#include <stdio.h>

struct student{
    int num;
    char name[20];
    char sex;
    int age;
    float score;
    char addr[30];
};//结构体类型声明，注意最后一定要加分号

int main() {
    struct student s={1001,"lele",'M',20,85.4,"Shenzhen"};
    struct student sarr[3];//定义一个结构体数组变量
    int i;
    //结构体输出必须单独去访问内部的每个成员
    s.num=1003;
    printf("%d %s %c %d %f %s\n",s.num,s.name,s.sex,s.age,s.score,s.addr);
    printf("--------------------------------------\n");
//    scanf("%d%s %c%d%f%s",&s.num,s.name,&s.sex,&s.age,&s.score,s.addr);
    for(i=0;i<3;i++)
    {
        scanf("%d%s %c%d%f%s",&sarr[i].num,sarr[i].name,&sarr[i].sex,&sarr[i].age,&sarr[i].score,sarr[i].addr);
    }
    for(i=0;i<3;i++)//结构体数组的输出
    {
        printf("%d %s %c %d %f %s\n",sarr[i].num,sarr[i].name,sarr[i].sex,sarr[i].age,sarr[i].score,sarr[i].addr);
    }

    return 0;
}
