#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Base {
  public:
    //重名静态成员函数
    static void func() {
        cout << "base static fun()" << endl;
    }
    static void func(int a) { // 重载
        cout << "base static fun(int)" << endl;
    }

  public:
    //静态成员属性
    static int m_A;
};
//静态成员属性,类内声明，类外实现
int Base::m_A = 10;

class Son : public Base {
  public:
    //重名静态成员函数
    static void func() {
        cout << "son static fun()" << endl;
    }

  public:
    //静态成员属性
    static int m_A;
};
//静态成员属性,类内声明，类外实现
int Son::m_A = 20;

//静态成员属性属于类，子类可以继承下来
void test01() {
    //如果子类和父类拥有同名的属性和方法，子类会屏蔽父类的成员(包括重载方法),但是依然独立存在
    //想调用父类的方法，必须加类名作用域

    //访问子类的m_A
    cout << Son::m_A << endl;
    //访问父类的m_A
    cout << Base::m_A << endl;

    //访问 子类中同名的函数
    Son::func();
    //访问 父类中同名的函数
    Base::func();
    Base::func(10);
    Son::Base::func(); // 子类::父类::方法
    Son::Base::func(10);
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}