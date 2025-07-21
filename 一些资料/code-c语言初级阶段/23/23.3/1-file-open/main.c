#include <stdio.h>

//练习文件打开
int main() {
    FILE *fp;//定义一个FILE类型的指针变量
    fp=fopen("file.txt","r+");//打开文件
    if(NULL==fp)//判断文件是否打开失败了
    {
        perror("fopen");//perror帮忙定位失败原因
        return -1;
    }
    char c;
//    c=fgetc(fp);
//    printf("%c\n",c);
//    c=fgetc(fp);
//    printf("%c\n",c);
    while((c=fgetc(fp))!=EOF)//读取文件内的所有内容
    {
        printf("%c",c);
    }
    printf("\n");
    c=fputc('H',fp);
    if(-1==c)
    {
        perror("fputc");
        return -1;
    }
    fclose(fp);//关闭文件
    return 0;
}
