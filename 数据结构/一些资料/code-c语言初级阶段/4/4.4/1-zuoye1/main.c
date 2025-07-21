#include <stdio.h>

int main() {
    int a=12321;
    int b=0,backup_a;
    backup_a=a;
    while(a)
    {
        printf("%d\n",a%10);//1232    2
        a=a/10;
    }
    //判断b和backup_a相等，就是对称数，如果不等，就不是对称数
    return 0;
}
