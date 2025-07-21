#include <stdio.h>

int main() {
    int i=1,total=0;
    do{
        total+=i;
        i++;
    }while(i<=100);//必须有分号，否则编译不通
    printf("total=%d\n",total);
    return 0;
}
