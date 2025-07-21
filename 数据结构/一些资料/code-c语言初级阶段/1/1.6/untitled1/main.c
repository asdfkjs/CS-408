#include <stdio.h>
void modify_pointer(int **p,int *q)//相对于C++这里是int **p;
{
    *p=q;//这里的写法和例1.2中的是非常类似的
}
int main() {
    int *p=NULL;
    int i=10;
    int *q=&i;
    modify_pointer(&p,q);//相对于C++这里是&p
    printf("after modify_pointer *p=%d\n",*p);
    return 0;
}
