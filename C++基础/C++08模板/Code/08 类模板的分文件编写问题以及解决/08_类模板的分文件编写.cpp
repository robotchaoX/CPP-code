#define _CRT_SECURE_NO_WARNINGS
#include "Person2.cpp" // 包含类模板cpp源文件
#include "Person2.h"
#include <iostream>
#include <string>

using namespace std;

// 类模板的分文件编写,头文件声明,源文件实现类模板
// 必须include类模板源cpp文件才可以

//建议 模板不要做分文件编写,写到一个类中即可,类内进行声明和实现，最后把后缀名改为.hpp 约定俗成

int main() {

    Person<string, int> p("猪八戒", 10);
    p.showPerson();

    // system("pause");
    return EXIT_SUCCESS;
}