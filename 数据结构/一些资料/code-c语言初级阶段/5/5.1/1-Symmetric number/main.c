#include <stdio.h>
//课时4作业1 判断一个数是否是对称数
int main() {
    int a,b=0,backup_a;
    scanf("%d",&a);//读取一个整型数
    backup_a=a;//把a的值备份一下
    while(a)
    {
        b=b*10+a%10;//b把原有的值乘以10，然后再加余数
        a=a/10;
    }
//    printf("b=%d\n",b);//为了辅助自己理解
    if(b==backup_a)
    {
        printf("yes\n");
    }else{
        printf("no\n");
    }
    return 0;
}
