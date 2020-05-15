#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 1、全局变量检测增强
// int a;
int a = 10; // c++重复定义

// 2、函数检测增强,参数类型增强,返回值检测增强,函数调用参数检测增强
int getRectS(int w, int h) {
    return w * h;
}
void test02() {
    getRectS(10, 10);
}

// 3、类型转换检测增强
void test03() {
    char *p = (char *)malloc(sizeof(64)); // malloc返回值是void*,指定类型
}

// 4、struct 增强
struct Person {
    int m_Age;
    // c++中struct可以加函数
    void plusAge() {
        m_Age++;
    };
};
void test04() {
    struct Person p0;
    Person p1; //使用时候可以不加struct关键字
    p1.m_Age = 10;
    p1.plusAge(); // struct函数
    cout << p1.m_Age << endl;
}

// 5、bool类型增强 C语言中没有bool类型
// true代表真（非0）, false代表假（0）
bool flag = true;
void test05() {
    cout << sizeof(bool) << endl;

    flag = 100;
    // bool类型 非0的值 转为 1 true， 0还是 0 false
    cout << flag << endl;
}

// 6、三目运算符增强
void test06() {
    int a = 10;
    int b = 20;

    cout << "ret = " << (a < b ? a : b) << endl;

    // C++中三目运算的结果是变量
    (a < b ? a : b) = 100; // b = 100 C++中返回的是变量

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

// 7、 const增强
// 全局const真正常量，受到只读保护，不可修改
const int m_A = 10; //常量初始化
void test07() {
    // 全局const受到只读保护，修改报错?？？
    cout << "m_A = " << m_A << endl;
    cout << "&m_A = " << &m_A << endl;
    int *pa = (int *)&m_A; // 临时指针
    // *pa = 100; // 指针无法修改原全局const Segmentation fault
    cout << "pa = " << pa << endl;
    cout << "*pa = " << *pa << endl;
    cout << "m_A = " << m_A << endl;

    // 局部const也是真正常量，指针修改不了const变量值
    const int m_B = 20; //常量初始化
    // m_B = 100; //直接改全局const报错
    cout << "&m_B = " << &m_B << endl;
    int *p = (int *)&m_B; //?? const取地址会分配临时内存
    *p = 200; // 修改临时开辟的内存,指针无法修改原局部const,不报错
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl; // 200
    cout << "m_B = " << m_B << endl; // 20

    //! 但是只要分配内存(用变量初始化)的const都可以用指针修改,例如下
    int cVar = 30;
    const int c_b = cVar; // const=变量，会分配内存,分配内存的都可以用指针修改
    cout << "c_b = " << c_b << endl; // 30
    int *cp = (int *)&c_b;
    *cp = 333; // 通过指针修改了
    cout << "c_b = " << c_b << endl; // 333
    cVar = 444; // const与初始化变量无关??
    cout << "c_b = " << c_b << endl; // 333

    // 全局const和局部const是真正的常量，可以初始化数组长度
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