#include <stdio.h>

int main() {
    char c[20];
    gets(c);//gets中放入我们字符数组的数组名即可
    puts(c);//puts等价于printf("%s\n",c); puts内放的参数是字符数组名
    return 0;
}
