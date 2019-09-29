#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

// 1、const分配内存 取地址会分配临时内存
// int *p = (int *)&m_A; //const取地址会分配临时内存
// 2、extern 编译器也会给const变量分配内存??
void test01() {
    const int m_A = 10;   // 不分配内存，m_A无法被修改
    int *p = (int *)&m_A; // const取地址会分配临时内存
    cout << "*p = " << *p << endl;
    *p = 20;
    cout << "*p = " << *p << endl;
    cout << "m_A = " << m_A << endl;
}

// 3、 用普通变量初始化 const 的变量
void test02() {
    int a = 10;
    const int b = a; // const=变量，会分配内存,只要分配内存的都可以用指针修改const

    int *p = (int *)&b;
    *p = 1000;
    a = 200;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

// // 4、 自定义数据类型  加const也会分配内存？？
// struct Person {
//     string m_Name; //姓名
//     int m_Age;
// };
// void test03() {
// const Person p1; // const未初始化？？
//     // p1.m_Name = "aaa";

//     Person *p = (Person *)&p1;
//     p->m_Name = "德玛西亚";
//     (*p).m_Age = 18; // const分配内存情况

//     cout << "姓名： " << p1.m_Name << " 年龄： " << p1.m_Age << endl;
// }

int main() {

    test01();
    test02();
    // test03();

    // system("pause");
    return EXIT_SUCCESS;
}