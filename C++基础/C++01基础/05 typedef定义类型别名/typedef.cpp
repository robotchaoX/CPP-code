#include <stdio.h>
#include <string.h>

// 任何声明变量的语句前面加上typedef之后，原来是变量的都变成一种类型。不管这个声明中的标识符号出现在中间还是最后.

// 定义变量类型
typedef unsigned char BYTE;
// 定义变量
BYTE b1, b2;

// 定义函数指针类型
typedef void (*PFUNC)(int a);
// 定义函数指针变量
PFUNC pfunc;
// 普通定义函数指针变量
void (*common_pfunc)(int a);

// 定义结构体类型
typedef struct Books {
    char title[50];
    int book_id;
} Book;

int main() {
    // 定义变量
    Book book;

    strcpy(book.title, "C 教程");
    book.book_id = 12345;

    printf("书标题 : %s\n", book.title);
    printf("书 ID : %d\n", book.book_id);

    return 0;
}