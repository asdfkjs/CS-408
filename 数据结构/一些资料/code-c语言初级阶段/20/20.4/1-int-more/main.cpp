#include <stdio.h>

//整型不同类型的演示，以及溢出演示
int main() {
    int i = 10;
    short a = 32767;
    short b = 0;
    long c;//32位的程序是4个字节，64位的是8个字节
    b = a + 1;//发生了溢出,解决溢出的办法是用更大的空间来存
    printf("%d\n", b);//b并不是32767
    printf("------------\n");
    unsigned int m = 3;
    unsigned short n = 0x8056;//无符号类型，最高位不认为是符号位
    unsigned long k = 5;
    b = 0x8056;
    printf("b=%d\n", b);//b是有符号类型，所以输出是负值
    printf("n=%u\n", n);//无符号类型要用%u，用%d是不规范的
    return 0;
    return 0;
}