#include <stdio.h>
#include <string.h>

int main() {
    char buf[20]="hello\nworld";
    FILE *fp;
    int ret;//存储函数的返回值
    //r+代表以文本方式打开文件
    fp=fopen("file.txt","rb+");
    if(NULL==fp)
    {
        perror("fopen");
        return -1;
    }
//    ret=fwrite(buf,sizeof(char),strlen(buf),fp);//把buf中的字符串写入文件
    char buf1[20]={0};
    ret=fread(buf1,sizeof(char),sizeof(buf1),fp);
    printf("%s\n",buf1);
    fclose(fp);
    return 0;
}
