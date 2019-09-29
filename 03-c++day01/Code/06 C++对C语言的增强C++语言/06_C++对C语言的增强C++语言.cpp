#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 1、全局变量检测增强
// int a;
int a = 10;

// 2、函数检测增强 ,参数类型增强,返回值检测增强,函数调用参数检测增强
int getRectS(int w, int h) { return w * h; }
void test02() { getRectS(10, 10); }

// 3、类型转换检测增强
void test03() {
    char *p = (char *)malloc(sizeof(64)); // malloc返回值是void*
}

// 4、struct 增强
struct Person {
    int m_Age;
    void plusAge() { m_Age++; }; // c++中struct可以加函数
};
void test04() {
    Person p1; //使用时候可以不加struct关键字
    p1.m_Age = 10;
    p1.plusAge();
    cout << p1.m_Age << endl;
}

// 5、 bool类型增强 C语言中没有bool类型
bool flag = true; //只有真或假 true代表 真（非0）  false 代表假（0）
void test05() {
    cout << sizeof(bool) << endl;

    flag = 100;
    // bool类型 非0的值 转为 1  ，0就转为0
    cout << flag << endl;
}

// 6、三目运算符增强
void test06() {
    int a = 10;
    int b = 20;

    cout << "ret = " << (a < b ? a : b) << endl;

    (a < b ? a : b) = 100; // b = 100 C++中返回的是变量

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

const int m_A = 10; // 全局const真正常量，受到只读保护，不可修改
// 但是只要分配内存的const都可以用指针修改,例如下
// int a = 10
// const int b = a; //const=变量，会分配内存,分配内存的都可以用指针修改
void test07() {
    const int m_B = 20; // 局部const真正常量，指针修改不了值
    // m_B = 100;
    int *p = (int *)&m_B; // 新开辟临时内存
    *p = 200;             // 指针无法修改原const
    cout << "*p = " << *p << endl;
    cout << "m_B = " << m_B << endl;

    // 全局const受到保护，修改报错?？？
    // cout << "m_A = " << m_A << endl;
    // cout << "&m_A = " << &m_A << endl;
    // int *pa = (int *)&m_A; // 新开辟临时内存?? Segmentation fault
    // *pa = 100;             // 指针无法修改原const
    // cout << "*pa = " << *pa << endl;
    // cout << "m_A = " << m_A << endl;

    // m_A m_B是真正的常量，可以初始化数组
    int arrA[m_A] = {1, 2, 3, 4}; // 可以初始化数组
    cout << "arrA[1] = " << arrA[1] << endl;
    int arrB[m_B] = {1, 2, 3, 4}; // 可以初始化数组
    cout << "arrB[1] = " << arrB[1] << endl;
}

int main() {

    test02();
    test03();
    test04();
    test05();
    test06();

    test07();

    // system("pause");
    return EXIT_SUCCESS;
}