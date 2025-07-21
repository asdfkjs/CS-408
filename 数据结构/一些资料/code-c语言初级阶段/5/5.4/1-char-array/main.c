#include <stdio.h>
//模拟printf("%s",c)操作
void print(char d[])
{
    int i=0;
    while(d[i])//当走到结束符时，循环结束
    {
        printf("%c",d[i]);
        i++;
    }
    printf("\n");
}
//如何初始化字符数组，字符串如何输出
//输出字符串乱码时，要去查看字符数组中是否存储了结束符'\0'
int main() {
    char c[6]= "hello";//使用这种方式初始化字符数组
    char d[5]="how";
    printf("%s\n",c);//使用%s来输出一个字符串，直接把字符数组名放到printf后面位置
    print(d);
    return 0;
}
