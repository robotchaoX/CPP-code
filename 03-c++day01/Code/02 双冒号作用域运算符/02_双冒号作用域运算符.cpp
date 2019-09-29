
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int atk = 200;
void test01() {
    int atk = 100;

    cout << "局部变量 ： " << atk << endl;
    //双冒号 作用域运算符  ::全局作用域命名空间
    cout << "：：全局作用域命名空间，全局变量 ： " << ::atk << endl;
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}
