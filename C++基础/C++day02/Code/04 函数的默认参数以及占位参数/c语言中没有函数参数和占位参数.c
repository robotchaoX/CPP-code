#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// C语言中形参没有默认参数,C也没有 占位参数

// C语言中没有 默认参数
void fun1(int x = 0) {
}

// C语言中没有 占位参数
void fun2(int a, int) {
}

int main() {

    // system("pause");
    return EXIT_SUCCESS;
}