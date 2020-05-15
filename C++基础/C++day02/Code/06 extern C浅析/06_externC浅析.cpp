// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "test1.h"

using namespace std;

// 可以多次声明extern "C"
extern "C" {
void show(); // show方法 按照C语言方式做连接
}

// g++ -std=c++11 -I ./ 06_externC浅析.cpp test1.c
// ./aout
int main() {
    // 报错？？？  undefined reference to `show' collect2: error: ld returned 1 exit status
    show(); //在C++中 函数是可以发生重载的，编译器会把这个函数名称偷偷改变_showv  void  // C语言并不支持函数重载

    // system("pause");
    return EXIT_SUCCESS;
}