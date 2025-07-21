#include <stdio.h>

int main() {
    FILE* fp;
    int i=123456;
    int ret;
    fp=fopen("file.txt","rb+");//以rb+模式打开文件
    if(NULL==fp)
    {
        perror("fopen");
        return -1;
    }
    //向文件中写入整型数，如果我们双击打开文件会发现乱码，因为打开文件都是以字符格式去解析的
//    ret=fwrite(&i,sizeof(int),1,fp);
    i=0;
    fread(&i,sizeof(int),1,fp);
    printf("i=%d",i);
    fclose(fp);
    return 0;
}
