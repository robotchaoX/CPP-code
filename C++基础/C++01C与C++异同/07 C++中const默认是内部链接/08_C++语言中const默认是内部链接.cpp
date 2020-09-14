#define _CRT_SECURE_NO_WARNINGS
#include "extern_c++.hpp"
#include <iostream>

using namespace std;

int main() {

    /*
        printf("g_extern_const_var = %d \n ", g_extern_const_var);
        printf("g_extern_var = %d \n ", g_extern_var);
    */

    // 告诉编译器变量在外部
    // extern const int g_const_var; //声明外部变量
    // extern const int g_var_comm; //声明外部变量

    //?? C++中默认const也是外部链接,不告诉也可以
    printf("g_const_var = %d \n ", g_const_var);

    // C++中默认全局变量也是外部链接,不告诉也可以
    printf("g_var_comm = %d \n ", g_var_comm);

    // system("pause");
    return EXIT_SUCCESS;
}