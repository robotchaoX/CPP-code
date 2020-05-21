#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Person {
  public:
    int m_A; // 普通成员变量

    // static静态成员变量,属于类,不属于某个对象
    static int m_Age_static; //加入static就是 静态成员变量,属于类
    // static静态成员变量，在类内声明，类外进行初始化
    static int m_s_must_init; // 不用可以不初始化,但是用到了必须类外初始化

    // static静态成员函数,属于类,不属于某个对象
    // static不可以访问 普通成员变量 //static可以访问 static静态成员变量
    static void func_static() { // 没有this指针
        // m_A = 10; //不可以访问 普通成员变量
        m_Age_static = 100; //可以访问 静态成员变量
        m_s_must_init = 1; // 不用可以不初始化,但是用到了必须类外初始化
        cout << "func调用" << endl;
    };

    //普通成员函数,可以访问普通成员变量，也可以访问静态成员变量
    void myFunc() { // 有this指针
        m_A = 100; // 可以访问 普通成员变量
        m_Age_static = 100; // 可以访问 静态成员变量
    }

  private:
    // static静态成员变量 也是有权限的
    static int m_static_private; //私有权限 在类外不能访问，但是可以初始化

    // static静态成员函数 也是有权限的
    static void func_static_private() {
        cout << "func2调用" << endl;
    }
};
// 类外初始化static静态成员
int Person::m_Age_static = -1; //类外初始化实现static
int Person::m_static_private = 10;
int Person::m_s_must_init; // 不用可以不初始化,但是用到了必须类外初始化

void test01() {
    // static静态成员变量访问
    // 1.通过对象访问属性
    Person p1;
    Person p2;
    p1.m_Age_static = 10;
    p2.m_Age_static = 20; // 共享类static属性
    cout << "p1 = " << p1.m_Age_static << endl; // 20
    cout << "p2 = " << p2.m_Age_static << endl; // 20
    // static属于类,对象间共享数据

    // 2.通过类名访问属性
    Person::m_Age_static = 30;
    cout << "通过类名访问Age" << Person::m_Age_static << endl;

    // static静态成员函数调用
    // 1.通过对象访问
    p1.func_static();
    // 2.通过类名访问
    Person::func_static();

    // static静态成员变量 也是有权限的
    // Person::m_static_private = 9; // 私有权限在类外无法访问
    // static静态成员函数 也是有权限的
    // Person::func_static_private(); // 无法访问
}

int main() {
    // int Person::m_s_Age = 0; // 必须全局类外初始化,main不行

    test01();

    return EXIT_SUCCESS;
}