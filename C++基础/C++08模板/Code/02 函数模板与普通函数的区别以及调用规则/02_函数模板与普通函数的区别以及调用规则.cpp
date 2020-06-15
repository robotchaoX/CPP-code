#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// 函数模板
template <class T>
T myPlus_T(T a, T b) {
    return a + b;
}

// 普通函数
int myPlus_g(int a, int b) {
    return a + b;
}

// 1 普通函数与函数模板区别
void test01() {
    int a = 10;
    int b = 20;
    char c = 'c'; // a = 97

    // 类型一致,自动推导类型
    myPlus_T(a, b); // 自动推导类型
    myPlus_T<int>(a, b); // 显式指定<类型>

    // 类型不一致,函数模板不可以进行隐式类型转换,类型推导不出来T
    // myPlus_T(a, c); // error 类型不一致,不会进行隐式类型转换,推导不出来T
    cout << myPlus_T<int>(a, c) << endl; //?? 显式指定<类型>

    // 普通函数 可以进行隐式类型转换
    cout << myPlus_g(a, c) << endl; // 10 + 99
}

// 2 普通函数和函数模板的调用规则
void myPrint(int a, int b) {
    cout << "普通函数调用 myPrint" << endl;
}

// 函数模板与普通函数重名,重载
template <class T>
void myPrint(T a, T b) {
    cout << "模板调用的myPrint" << endl;
}

// 函数模板重载
template <class T>
void myPrint(T a, T b, T c) {
    cout << "模板调用的myPrint(a,b,c)" << endl;
}

//通过模板生成的函数  叫 模板函数
// void myPrint(int a, int b, int c) {
// }

void test02() {
    int a = 10;
    int b = 20;

    // 类型匹配: 普通函数 > 函数模板
    // 类型匹配的模板 > 类型转换的普通函数

    // 1、如果出现重载  优先使用普通函数调用,如果没有实现，出现错误
    myPrint(a, b); // 优先普通函数

    // 2、如果想强制调用模板，那么可以使用空参数列表
    myPrint<>(a, b); // <>调用模板

    // 3、函数模板可以发生重载
    int c = 30;
    myPrint(a, b, c); // 模板重载

    // 4、如果函数模板可以产生更好的匹配，那么优先调用函数模板
    char c1 = 'c';
    char c2 = 'd';
    myPrint(c1, c2); // 类型匹配优先
}

int main() {

    test01();

    // test02();

    // system("pause");
    return EXIT_SUCCESS;
}