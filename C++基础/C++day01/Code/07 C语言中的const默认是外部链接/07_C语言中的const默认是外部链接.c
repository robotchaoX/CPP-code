#define _CRT_SECURE_NO_WARNINGS
#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // extern const int a_c; //声明外部变量
    // extern const int b_g; //声明外部变量

    // C语言中默认const是外部链接,不告诉也可以
    printf("a_c = %d \n ", a_c);

    // C语言中默认全局变量是外部链接,不告诉也可以
    printf("b_g = %d \n ", b_g);

    // system("pause");
    return EXIT_SUCCESS;
}