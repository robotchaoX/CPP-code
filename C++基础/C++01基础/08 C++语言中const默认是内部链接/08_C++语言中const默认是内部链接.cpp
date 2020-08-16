#define _CRT_SECURE_NO_WARNINGS
#include "test2.hpp"
#include <iostream>

using namespace std;

int main() {

    printf("x_c = %d \n ", x_c);
    printf("y_g = %d \n ", y_g);

    // extern const int a_c; //声明外部变量
    // extern const int b_g; //声明外部变量

    //?? C++中默认const也是外部链接,不告诉也可以
    printf("a_c = %d \n ", a_c);

    // C++中默认全局变量也是外部链接,不告诉也可以
    printf("b_g = %d \n ", b_g);

    // system("pause");
    return EXIT_SUCCESS;
}