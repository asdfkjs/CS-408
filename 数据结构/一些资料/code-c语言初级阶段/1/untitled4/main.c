#include <stdio.h>

int main() {
//写一个排序
    int a[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    int i, j, temp;

    //冒泡排序
    for (i = 0; i < 10; i++) {
        for (j = i + 1; j < 10; j++) {
            if (a[i] > a[j]) {
                temp = a[j];//
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
    for (i = 0; i < 10; i++) {
        printf("%d ", a[i]);//输出
    }
    printf("\n");//换行
    return 0;


}
