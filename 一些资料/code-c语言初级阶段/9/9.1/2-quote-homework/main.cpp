#include <stdio.h>
#include <stdlib.h>

//当子函数要修改主函数中的p，那么就加引用。引用如何实现的，完全不需要去关心
void modify_pointer(char *&p)
{
    p=(char*)malloc(100);//申请100个字节大小的空间
    fgets(p,100,stdin);//stdin代表标准输入，fgets是安全的
}

//课时8作业2 练习C++的引用的使用
int main() {
    char *p=NULL;
    modify_pointer(p);
    puts(p);
    free(p);//申请的空间不使用后，记得free，避免扣分
    return 0;
}
