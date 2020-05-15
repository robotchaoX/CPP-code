#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1、全局变量检测增强
int a; // c当做声明,下面定义
int a = 10; // c++重复定义

// 2、函数形参检测增强
int getRectS(w, h) { // c可以不指定形参类型只是waring
}
void test02() {
    getRectS(10, 10, 10);
}

// 3、类型转换检测增强
void test03() {
    char *p = malloc(sizeof(64)); // malloc返回值是void*，c可以不指定malloc类型
}

// 4、struct 增强
struct Person {
    int m_Age;
    // void plusAge(); // c语言中struct不可以加函数
};
void test04() {
    struct Person p1; // c使用时候必须加入struct关键字
}

// 5、 bool类型增强 C语言中没有bool类型
// bool flag;

// 6、三目运算符增强
void test06() {
    int a = 10;
    int b = 20;

    printf("ret = %d \n", a > b ? a : b); // 20

    // C语言三目运算的结果是变量的数值
    // (a > b ? a : b) = 100; // 20 = 100 C语言返回的是数值

    // C语言中想模仿C++写
    *(a > b ? &a : &b) = 100;
    printf("a = %d ,b = %d \n", a, b);
}

// 7、 const增强
// c全局const受到只读保护，不可以改
const int m_A = 10;
void test07() {
    //全局constat受到保护，不可以改
    // m_A = 100; //直接改全局const报错
    //全局constat受到保护，不可以改，修改报错Segmentation fault
    // int *pa = (int *)&m_A;
    // *pa = 200; // 通过指针改全局const也报错
    // printf("*pa = %d , m_A = %d \n", *pa, m_A);

    // c局部const是伪常量,可以通过指针修改(c++局部const是真正常量)
    const int m_B = 20;
    // m_B = 100;//直接改局部const报错
    // 可以通过指针修改局部const
    int *p = (int *)&m_B;
    *p = 200; // 可以通过指针修改局部const
    printf("*p = %d , m_B = %d \n", *p, m_B);

    // c全局const可以初始化数组？？error
    // int arrA[m_A] = {1, 2, 3, 4}; // 可以初始化数组？？error
    // 局部const不能初始化数组长度
    // int arrB[m_B] = {1, 2, 3, 4}; // 不可以初始化数组
}

int main() {

    test02();

    test03();

    test04();

    test06();

    test07();

    return EXIT_SUCCESS;
}