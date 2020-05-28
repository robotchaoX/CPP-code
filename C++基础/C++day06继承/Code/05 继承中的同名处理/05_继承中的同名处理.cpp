#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Base {
  public:
    Base() {
        // m_A = 100;
    }

    // 子类父类方法重名
    void fun() { // 派生类屏蔽基类同名成员(包括基类的重载方法)
        cout << "Base func调用" << endl;
    }
    // 子类父类方法重名的重载
    void fun(int a) { // 派生类屏蔽基类同名成员(包括基类的重载方法)
        cout << "Base func(int a)调用" << endl;
    }

    void showBase() {
        cout << "Base showBase 调用" << endl;
    }

  public:
    int m_A = 111; // 子类父类属性重名，变量空间同时存在,如未指明作用域命名空间按就近原则处理
};

class Son : public Base {
  public:
    Son() {
        // m_A = 200;
    }

    // 子类父类方法重名
    void fun() {
        cout << "Son func调用" << endl;
    }

    void showSon() {
        cout << "Base showSon 调用" << endl;
    }

  public:
    int m_A = 222; // 子类父类属性重名，变量空间同时存在,如未指明作用域命名空间按就近原则处理
};

void test01() {
    Son s1;

    //! 派生类屏蔽基类同名成员属性(重名变量空间同时独立存在),但指明类名仍可以访问
    cout << "s1.m_A = " << s1.m_A << endl;
    cout << "s1.Son::m_A = " << s1.Son::m_A << endl; // 默认当前类命名空间作用域
    //指明类名仍可以访问,可调用 父类中 的m_A
    cout << "s1.Base::m_A = " << s1.Base::m_A << endl; // 指明命名空间作用域

    //! 派生类屏蔽基类同名成员(包括基类的重载方法),但指明类名仍可以访问
    s1.fun();
    s1.Son::fun(); // 默认当前类命名空间作用域
    //指明类名仍可以访问,可调用父类的func
    s1.Base::fun(); // 指明类名命名空间作用域,访问基类方法

    //调用父类的func重载方法
    // s1.fun(10); // error 派生类屏蔽基类同名成员(包括基类的重载方法),但指明类名仍可以访问
    s1.Base::fun(10); // 指明类名命名空间作用域,访问基类重载方法

    // 不重名方法
    s1.showBase(); // 继承自父类
    s1.Base::showBase(); // 可以指明类名命名空间作用域
    s1.showSon(); // 子类方法
    s1.Son::showSon(); // 可以指明类名命名空间作用域
}

//如果子类和父类拥有同名的属性和方法，子类会屏蔽父类的成员(包括重载方法),但是依然独立存在
//想调用父类的方法，必须加类名作用域
//如果子类与父类的成员函数名称相同，子类会把父类的所有的同名版本都隐藏掉

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}