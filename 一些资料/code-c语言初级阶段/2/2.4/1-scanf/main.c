#include <stdio.h>

//scanf用来读取标准输入，scanf把标准输入内的内容，需要放到某个变量空间里，因此变量必须取地址
//scanf会阻塞，是因为标准输入缓冲区是空的
int main() {
    int i;
    char c;
    float f;
    scanf("%d",&i);
    printf("i=%d\n",i);//把标准缓冲区中的整型数读走了
    fflush(stdin);//清空标准输入缓冲区
    scanf("%c",&c);
    printf("c=%c\n",c);//输出字符变量c
//    scanf("%f",&f);
//    printf("f=%f\n",f);
    return 0;
}
