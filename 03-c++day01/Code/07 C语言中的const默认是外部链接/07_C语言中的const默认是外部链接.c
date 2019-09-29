#define _CRT_SECURE_NO_WARNINGS
#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    extern const int a; //告诉编译器在a在外部
    printf("a = %d \n ", a);

    // system("pause");
    return EXIT_SUCCESS;
}