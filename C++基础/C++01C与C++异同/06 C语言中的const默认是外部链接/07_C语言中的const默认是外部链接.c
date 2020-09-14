#define _CRT_SECURE_NO_WARNINGS
#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    /*
        printf("g_extern_const_var = %d \n ", g_extern_const_var);
        printf("g_extern_var = %d \n ", g_extern_var);
    */

    // extern const int g_const_var; //声明外部变量
    // extern const int g_var_comm; //声明外部变量

    // C语言中默认const是外部链接,不告诉也可以
    printf("g_const_var = %d \n ", g_const_var);

    // C语言中默认全局变量是外部链接,不告诉也可以
    printf("g_var_comm = %d \n ", g_var_comm);

    // system("pause");
    return EXIT_SUCCESS;
}