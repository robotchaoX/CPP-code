#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Base {
  public:
    Base() {
        cout << "Base默认构造函数调用" << endl;
    }
    Base(int base_a1) {
        m_BaseA = base_a1;
        cout << "Base有参构造函数调用:" << m_BaseA << endl;
    }
    Base(const Base &bs) {
        m_BaseA = bs.m_BaseA;
        cout << "Base拷贝构造函数调用:" << m_BaseA << endl;
    }

    ~Base() {
        cout << "Base的析构函数调用" << endl;
    }

  private:
    int m_BaseA;
};

// 子类会继承父类的成员属性，成员函数
//! 但是 子类 不会继承 父类 构造函数 和 析构函数
//! 构造时先构造 父类 再构造 子类 ，析构时相反
// 只有父类自己知道如何构造和析构自己的属性，而子类不知道
class Son : public Base {
  public:
    // 构造时先构造 父类 再构造 子类
    Son() { // 先调用父类的构造函数，再调用子类的构造函数
        cout << "Son默认构造函数调用" << endl;
    }

    // 子类利用初始化列表 显式调用 基类有参构造函数
    Son(int son_a, int son_b) : Base(son_a) {
        m_SonB = son_b;
        cout << "Son有参构造函数调用:" << m_SonB << endl;
        cout << "利用初始化列表显示调用 基类有参构造函数" << endl;
    }

    ~Son() { // 析构时 自动调用 基类析构函数,析构顺序与构造顺序相反
        cout << "Son的析构函数调用" << endl;
    }

  private:
    int m_SonB;
};

void test01() {
    // 构造时先构造 父类 再构造 子类

    Son s1; // 子类默认构造
    cout << "----- " << endl;

    Son s2(10, 20); // 子类利用初始化列表 显式调用 基类有参构造
    cout << "----- " << endl;
}

class Base2 {
  public:
    Base2(int a) { // 子类可以利用初始化列表显示调用 基类有参构造
        this->m_A = a;
        cout << "Base2有参构造函数调用" << endl;
    }
    int m_A;
};

class Son2 : public Base2 {
  public:
    //子类利用初始化列表 显式调用 基类有参构造
    Son2(int a) : Base2(a) {
        cout << "Son2有参构造函数调用" << endl;
        cout << "利用初始化列表显示调用 基类有参构造函数" << endl;
    }
};

void test02() {
    Son2 s2(1000);
}

int main() {

    test01();

    cout << "-----------" << endl;

    test02();

    // system("pause");
    return EXIT_SUCCESS;
}