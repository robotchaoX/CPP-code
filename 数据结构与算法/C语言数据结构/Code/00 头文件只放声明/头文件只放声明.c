#include "extern.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc 头文件只放声明.c extern.c

// 声明外部变量，局部声明，全局声明都可以，可以重复声明
extern int a;

int main() {

    // 声明外部变量，局部声明，全局声明都可以
    extern int a;
    printf("a = %d\n", a);

    return EXIT_SUCCESS;
}