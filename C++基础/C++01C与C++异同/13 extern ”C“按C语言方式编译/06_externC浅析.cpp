// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "c_only.h"

using namespace std;

// 可以多次声明extern "C"
extern "C" {
//声明
void show(); // show方法 按照C语言方式做连接
}
//实现
void show() {
    printf("show hello world \n");
}

/**
     g++ -std=c++11 -I ./ 06_externC浅析.cpp c_only.c
     ./aout
 */
int main() {
    // 报错？？？  undefined reference to `show' collect2: error: ld returned 1 exit status
    show(); //在C++中 函数是可以发生重载的，编译器会把这个函数名称偷偷改变_showv  void  // C语言并不支持函数重载

    only_C_exe();

    // system("pause");
    return EXIT_SUCCESS;
}