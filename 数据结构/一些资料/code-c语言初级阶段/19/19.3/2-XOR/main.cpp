#include <stdio.h>

int main() {
    int i;
    int arr[5] = { 8 ,5, 3, 5, 8 };
    int result = 0;
    for(i=0;i<5;i++)
    {
        result=result^arr[i];//异或满足交换律
    }
    printf("%d\n", result);//输出为3
    return 0;
}
