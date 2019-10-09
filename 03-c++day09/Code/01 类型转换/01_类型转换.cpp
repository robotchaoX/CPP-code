#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 静态转换 static_cast
// static_cast使用   static_cast<目标类型>(原始对象)

// 基础类型
void test01() {
    char a = 'a';
    double d = static_cast<double>(a); // char 转 double
    cout << "d = " << d << endl;
}

// 父子类之间转换
class Base {};
class Child : public Base {};
class Other {};
void test02() {
    Base *base = NULL;
    Child *child = NULL;

    //把base转为 Child* 类型 向下  不安全
    Child *child2 = static_cast<Child *>(base);

    //把child 转为 Base* 向上  安全
    Base *base2 = static_cast<Base *>(child);

    //转other类型 转换无效
    // Other * other = static_cast<Other*>(base);
}

// 动态转换 dynamic_cast
// dynamic_cast非常严格，失去精度 或者不安全都不可以转换

//基础类型不可以转换
void test03() {
    char c = 'a';
    // dynamic_cast非常严格，失去精度 或者不安全都不可以转换
    // double d = dynamic_cast<double>(c);
}

// 父子类之间转换
class Base0 {};
class Child0 : public Base0 {};
class Other0 {};

class Base2 {
    virtual void func(){};
};
class Child2 : public Base2 {
    virtual void func(){};
};
class Other2 {};

void test04() {

    Base0 *base0 = NULL;
    Child0 *child0 = NULL;
    // child转Base2 *  安全
    Base0 *base00 = dynamic_cast<Base0 *>(child0); // 不发生多态可以转换

    // base 转Child2 * 不安全
    // Child0 *child00 = dynamic_cast<Child0 *>(base0); // 不发生多态不可以转换

    Base2 *base = NULL;
    Child2 *child = NULL;
    // dynamic_cast 如果发生了多态，那么可以让基类转为派生类 ，向下转换
    // 发生多态 不管父转子还是子转父都是安全的
    Base2 *base3 = new Child2;
    Child2 *child3 = dynamic_cast<Child2 *>(base3);
}

int main() {

    test01();
    test02();
    test03();
    test04();

    // system("pause");
    return EXIT_SUCCESS;
}