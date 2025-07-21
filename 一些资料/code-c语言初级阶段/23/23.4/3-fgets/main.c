#include <stdio.h>

int main()
{
    char buf[20]={0};//用于存储读取数据
    FILE* fp;
    fp=fopen("file.txt","r+");//可读可写打开文件
    if(NULL==fp)
    {
        perror("fopen");
        return -1;
    }
    //一次读一行，读空文件
    while(fgets(buf,sizeof(buf),fp)!=NULL)//fgets读取到文件结束时返回NULL
    {
        printf("%s",buf);
    }
    return 0;
}
