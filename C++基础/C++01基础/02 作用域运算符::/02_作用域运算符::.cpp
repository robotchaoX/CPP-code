#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// 全局变量
int sameNameVar = 222;

void test01() {
    // 局部变量
    int sameNameVar = 111;
    cout << "局部变量 ： " << sameNameVar << endl;

    // 双冒号::作用域运算符
    // ::全局作用域命名空间
    cout << "::全局变量 ： " << ::sameNameVar << endl;
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}
