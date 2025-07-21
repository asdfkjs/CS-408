#include <stdio.h>

struct student_type1{
    double score;//double是一种浮点类型，8个字节，浮点分为float和double，记住有这两种即可
    short age;//short 是整型，占2个字节
};

struct student_type2{
    double score;
    int height;//如果两个小存储之和是小于最大长度8，那么它们就结合在一起
    short age;
};

struct student_type3{
    int height;
    char sex;
    short age;
};
//结构体对齐
int main() {
    struct student_type1 s1;
    struct student_type2 s2={1,2,3};
    struct student_type3 s3;
    printf("s1 size=%d\n",sizeof(s1));
    printf("s2 size=%d\n",sizeof(s2));
    printf("s3 size=%d\n",sizeof(s3));
    return 0;
}
