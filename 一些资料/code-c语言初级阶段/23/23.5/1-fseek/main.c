#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fp;
    char str[20]="hello\nworld";
    int len=0;//用于保存字符串长度
    long pos;
    int ret;//接函数返回值
    fp =fopen("file.txt","r+");//打开文件
    if(NULL==fp)
    {
        perror("fopen");
        return -1;
    }
    len=strlen(str);
    fwrite(str,sizeof(char),len,fp);
    ret=fseek(fp,-5,SEEK_CUR);
    if(ret!=0)
    {
        perror("fseek");
        fclose(fp);
        return -1;
    }
    pos= ftell(fp);
    printf("now pos=%ld\n",pos);
    memset(str,0,sizeof(str));//清空str
    fread(str,sizeof(char),sizeof(str),fp);//读取
    printf("str=%s\n",str);
    return 0;
}
