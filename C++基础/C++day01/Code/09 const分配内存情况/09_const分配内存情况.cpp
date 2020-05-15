#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

// 1、const分配内存 取地址会分配临时内存??
// int *p = (int *)&m_A; //const取地址会分配临时内存
void test01() {
    const int m_A = 10; //* 常量初始化const不会分配内存，m_A无法被修改
    cout << "--&m_A = " << &m_A << endl;
    int *p = (int *)&m_A; //?? const取地址会分配临时内存
    cout << "*p = " << *p << endl; // 10

    *p = 222; // 修改临时开辟的内存,指针无法修改原局部const,不报错
    cout << "*p = " << *p << endl; // 222
    cout << "m_A = " << m_A << endl; // 10
    //?? 地址相同,值却不同
    cout << "--p = " << p << endl;
    cout << "--&m_A = " << &m_A << endl;
}
// 2、extern 编译器也会给const变量分配内存??

//! 只要分配内存的const都可以用指针修改

// 3、 用普通变量初始化 const 的变量, 会分配内存？？可以用指针修改
void test02() {

    // 用变量初始化的const可以用指针修改
    int cVar = 30;
    const int c_b = cVar; // 变量初始化const会分配内存
    // const=变量,分配内存的都可以用指针修改
    cout << "c_b = " << c_b << endl; // 30
    int *p = (int *)&c_b; // 分配内存的都可以用指针修改
    *p = 333; // 通过指针修改了
    cout << "cVar = " << cVar << endl;
    cout << "c_b = " << c_b << endl; // 333
    cVar = 444; // const与初始化变量无关??
    cout << "c_b = " << c_b << endl; // 333
}

// 4、 自定义数据类型, 加const也会分配内存？？可以用指针修改
struct Person {
    string m_Name; //姓名
    int m_Age;
};
void test03() {
    const Person p1 = {"jeck", 18}; // 自定义数据类型const会分配内存
    // p1.m_Name = "tom"; // 不可修改

    Person *p = (Person *)&p1; // 分配内存的都可以用指针修改
    p->m_Name = "德玛西亚"; // 通过指针修改了
    (*p).m_Age = 18; // const分配内存情况

    cout << "姓名： " << p1.m_Name << " 年龄： " << p1.m_Age << endl;
}

int main() {

    test01();

    test02();

    test03();

    // system("pause");
    return EXIT_SUCCESS;
}