#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void mySwap(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
    // cout << "mySwap::a = " << a << endl;
    // cout << "mySwap::b = " << b << endl;
}

void test01() {
    int a = 10;
    int b = 20;
    mySwap(a, b); //值传递

    cout << "值传递" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

//地址传递
void mySwap2(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void test02() {
    int a = 10;
    int b = 20;
    mySwap2(&a, &b);

    cout << "地址传递" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

//引用传递 类似传地址
void mySwap3(int &a, int &b) //&a = a &b = b
{
    int tmp = a;
    a = b;
    b = tmp;
}

void test03() {
    int a = 10;
    int b = 20;
    mySwap3(a, b);

    cout << "引用传递" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

//引用的注意事项
// 1、 引用必须引一块合法的内存空间
// int &a = 10; // 不合法，引用必须引一块合法的内存空间
// 2、不要返回局部变量的引用
// 函数的返回值是引用&
int &temref() {
    int aa = 10; // 局部变量，报错
    // static int aa = 10; // static 全局生存周期,不会报错
    cout << "aa = " << aa << endl;
    //  warning: reference to local variable ‘aa’ returned [-Wreturn-local-addr]
    return aa; // 返回局部变量aa的引用
}

void test04() {
    // int &a = 10; // 引用必须引一块合法的内存空间
    cout << "temref()" << temref() << endl; // 第一次10是编译器做了优化
    cout << "temref()" << temref() << endl; // 接收的返回值为局部变量， 报错 Segmentation fault
    cout << "temref()" << temref() << endl;

    int &ret = temref(); // 报错 Segmentation fault

    cout << "ret = " << ret << endl; //第一次10是编译器做了优化
    cout << "ret = " << ret << endl;
    cout << "ret = " << ret << endl;
    cout << "ret = " << ret << endl;
    cout << "ret = " << ret << endl;
}

int &doWork2() {
    // int a = 10; // 局部变量，报错
    static int a = 10; // static 全局生存周期
    cout << "aa = " << a << endl;
    cout << "aa = " << a << endl;
    return a;
}
void test05() {
    int &ret = doWork2();

    //如果函数的返回值是引用，那么这个函数调用可以作为左值

    doWork2() = 1000; //相当于写了 a = 1000;
    cout << " doWork2():" << doWork2() << endl;
    cout << " doWork2():" << doWork2() << endl;
}

int main() {

    test01();

    test02();

    test03();

    test05();

    test04(); // 报错 Segmentation fault

    // system("pause");
    return EXIT_SUCCESS;
}