#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//现有 n （n>N）个数保存在一维数组M 中，需要查找 M 中最小的 10 个数
//法一：堆排序 大根堆
//法二：快速排序
//法三：选择排序

#define N 100
typedef int elem_type;
typedef struct {
    elem_type *data;
    int len;
}ssTable;
void init_st(ssTable &st,int len){
    st.len=len;
    st.data=(int *) malloc(sizeof (elem_type)*st.len);
    srand(time(NULL));
    int x=0;
    for (int i = 0; i <N ; ++i) {
        st.data[i]=rand()%100;
    }
}
void put_table(elem_type *s){
    for (int i = 0; i <10 ; ++i) {
        printf("%5d",s[i]);
    }
    printf("\n");
}

void selectSort(ssTable s,int n) {
    int i, j;
    int array[11]={999,999,999,999,999,999,999,999,999,999};//搞11个是为了方便移动，最后一个不输出

    //将前面10个数，从小到大放入array中
    for ( i = 0; i <10 ; ++i) {
        int insertValue=s.data[i];
        for (j = i-1;  j>=0&&array[j]>insertValue; j--) {
            array[j+1]=array[j];
        }
        array[j+1]=insertValue;
    }
    //从第10个数开始，小于前面有序的10个数，就放进去
    for ( i = 10; i <N ; ++i) {
        int insertValue=s.data[i];
        for (j =9; j>=0&&array[j]>insertValue; j--) {
            array[j+1]=array[j];
        }
        array[j+1]=insertValue;
    }


    for (int k = 0; k <10 ; ++k) {
        printf("%5d",array[k]);
    }
}
int main() {
    ssTable st;
    init_st(st,N);
    put_table(st.data);
    selectSort(st,9);
    return 0;
}
