#include <stdio.h>
//scanf读取字符串操作，会自动往字符数组中放结束符
int main() {
    char c[10];
    char d[10];
//    scanf("%s",c);//字符数组名c中存储了数组的起始地址，因此不需要取地址
//    printf("%s\n",c);
    scanf("%s%s",c,d);
    printf("c=%s,d=%s\n",c,d);
    return 0;
}
