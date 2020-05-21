#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Person {
  public:
    Person() {
        // this 永远执行本体
        this->m_A_normal = 0;
        cout << "构造() " << m_B_const << endl;
        this->m_C_mutable = 0;
    }

    Person(int b) : m_B_const(b) { // 初始化表初始化const变量
        this->m_A_normal = 0;
        cout << "构造(int b) " << m_B_const << endl;
        this->m_C_mutable = 0;
    }

    void show_normal() {
        cout << "void show_normal()" << endl;
    }

    // 常成员函数
    void show_const() const {
        // m_A = 100;   // 常成员函数 不允许修改指针指向的值
        cout << "void show_const() const " << endl;
    }

    // 常成员函数
    // (const Person * const this)
    void must_modify_const() const { // 常成员函数 不允许修改指针指向的值
        // this->m_A = 1000; // error 不允许修改属性
        this->m_C_mutable = 1000; // 只允许修改mutable声明的属性
        cout << "m_C_mutable = " << this->m_C_mutable << endl;
    }

    int m_A_normal;
    const int m_B_const = -1; // 必须初始化const,或者初始化表
    mutable int m_C_mutable; // 执意要在常成员函数修改的属性,只能是mutable声明属性
};

void test01() {
    Person p0(55); // 初始化表初始化const

    Person p1; // 默认值初始化const

    p1.must_modify_const(); // 执意要在常成员函数修改的属性,只能是mutable属性
}

void test02() { //常对象 不允许修改属性
    const Person p2;

    //常对象 可以访问普通属性
    cout << p2.m_A_normal << endl;
    //常对象 可以访问const属性
    cout << p2.m_B_const << endl;

    //! 常对象 不可以调用普通成员函数
    // p2.show_normal(); // error
    // 常对象 只能调用常函数
    p2.show_const(); // 常函数show2()
}

int main() {

    test01();
    test02();

    // system("pause");
    return EXIT_SUCCESS;
}