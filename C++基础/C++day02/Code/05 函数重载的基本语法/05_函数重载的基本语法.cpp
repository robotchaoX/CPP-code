#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//函数重载
// C++中 函数名称可以重复
// 必须在同一个作用域,函数名称相同
// 函数的参数 个数不同 或者 类型不同  或者 顺序不同
void func() {
    cout << "无参数的func" << endl;
}

void func(int a) {
    cout << "有参数的func(int a)" << endl;
}

void func(double a) { // 类型不同
    cout << "有参数的func(double a)" << endl;
}

void func(double a, int b) { // 个数不同
    cout << "有参数的func(double a ,int b)" << endl;
}

void func(int a, double b) { // 顺序不同
    cout << "有参数的func(int a ,double b)" << endl;
}

// 返回值不可以作为函数重载的条件
// int func(int a, double b) {
//     cout << "返回值不可以作为函数重载的条件" << endl;
//     return 1;
// }

void test01() {
    func(1.1, 3);
    func(1, 3.14);
}

//当函数重载 碰到了 默认参数时候，要注意避免二义性问题
void func2(int a, int b = 10) {
}
void func2(int a) { // 二义,与默认参数冲突
}

void test02() {
    // func2(10); // 二义性问题
}

//引用不能作为重载的条件
void func3(int a) {
    cout << " int a : " << a << endl;
}
void func3(int &a) { // 二义,与非引用冲突
    cout << " int &a : " << a << endl;
}
void test03() {
    int a = 3;
    // func3(a); //引用不能作为重载的条件
}

// const不能作为重载条件
// void func4(int a) {
//     cout << " int a : " << a << endl;
// }
void func4(const int a) { // 重复定义
    cout << " const int a : " << a << endl;
}
void test04() {
    int a = 4;
    func4(a); // const与非const重复定义
}

//引用不能作为重载的条件
void func5(int &a) { //引用不能作为重载的条件
    cout << " int &a : " << a << endl;
}
// const引用作为重载的条件
void func5(const int &a) { // const也是可以作为重载的条件  int tmp = 10; const int &a = tmp;
    cout << "const int &a : " << a << endl;
}

void test05() {
    int a = 10;
    func5(a); // 合法引用
    func5(10); // const重载，10不是合法的引用，但是const临时内存是合法的
}

int main() {
    test01();

    test02();

    test03();

    test04();

    test05();

    // system("pause");
    return EXIT_SUCCESS;
}