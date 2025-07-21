#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

char i[4] = {0};         //资源名称(共4类资源）
int Max[5][4] = {0};     //各进程最大需求矩阵
int Need[5][4] = {0};    //尚需资源矩阵
int Available[4] = {0};  //可用资源矩阵
int Request[4] = {0};    //请求资源向量
int Allocation[5][4] = {0};//各进程已分配资源数量
int temp[4] = {0};        //统计已分配资源
int M = 5;//进程共有5个
int N = 4;//资源共有4类


void init() {            //初始化
    for (int j=0; j < 4; j++) {
        printf("Please enter a name for the %d resource:", j);
        fflush(stdin);    //清空输入流缓冲区的字符（引入了头文件<stdlib.h>）
        scanf("%c", i);
        printf("the resource number:");    //接下来需要输入个资源初始个数
        scanf("%d", &Available[j]);        //这里容易忘记加&符号
    }

//    for (int m = 0; m < 5; m++) {
//        for (int n = 0; n < 4; n++) {
//            printf("please input the Max of course:");
//            scanf("%d", Max[m][n]);         //各进程最大需求矩阵
//            printf("please enter the resource allocated for the %d process: ", n);  //输入各进程已分配资源数
//            scanf("%d", Allocation[m][n]);
//            if (Allocation[m][n] <= Max[m][n]) {
//                Need[m][n] = Max[m][n] - Allocation[m][n];
//                int flag = true;
//                temp[n] += Allocation[m][n];
//            }
//        }
//    }
//    //求得系统中可利用资源数量
//    for (int j = 0; j < 4; j++) {
//        Available[j] = Available[j] - temp[j];
//    }
}

int main() {
    init();
//    for (int m = 0; m < 5; m++) {
//        for (int n = 0; n < 4; n++) {
//            printf("please input the Max of course:");
//            scanf("%d", &Max[m][n]);         //各进程最大需求矩阵
//            printf("please enter the resource allocated for the %d process: ", n);  //输入各进程已分配资源数
//            scanf("%d", &Allocation[m][n]);
//            if (Allocation[m][n] <= Max[m][n]) {
//                Need[m][n] = Max[m][n] - Allocation[m][n];
//                int flag = true;
//                temp[n] += Allocation[m][n];
//            }
//        }
//    }
    //求得系统中可利用资源数量
//    for (int j = 0; j < 4; j++) {
//        Available[j] = Available[j] - temp[j];
//    }
    return 0;
}