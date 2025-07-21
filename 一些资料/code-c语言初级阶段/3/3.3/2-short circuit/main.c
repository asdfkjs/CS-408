#include <stdio.h>

//逻辑与和逻辑或 短路运算
int main() {
    int i=0;
    i&&printf("you can't see me !\n");//当i为假时，不会执行逻辑与后的表达式，称为短路运算
    i=1;
    i||printf("you can't see me !\n");
    return 0;
}
