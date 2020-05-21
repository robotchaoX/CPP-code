#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyClass {
  public:
    MyClass() {
        cout << "默认构造函数" << endl;
    }

    MyClass(int a) {
        cout << "有参构造函数" << endl;
    }

    // 不写系统会提供默认拷贝构造函数
    // MyClass(const MyClass &m) {
    //     m_A = m.m_A;
    //     cout << "拷贝构造函数" << endl;
    // }

  public:
    int m_A;
};

//系统默认给一个类提供 3个函数  默认构造 、 拷贝构造 、 析构函数

// 1 当我们提供了有参构造函数，那么系统就不会在给我们提供默认构造函数了
//但是 系统还会提供默认拷贝构造函数 , 进行简单的值拷贝

void test01() {
    MyClass c1(1); // 有参
    c1.m_A = 10;
    MyClass c2(c1); // 自动提供拷贝构造函数
    cout << c2.m_A << endl;
}

// 2 当我们提供了 拷贝构造，那么系统就不会提供 默认无参构造了
class MyClass2 {
  public:
    // 提供了 拷贝构造，但不提供无参构造会报错
    MyClass2() {
        cout << "默认构造函数" << endl;
    }

    // 提供了拷贝构造，那么系统就不会提供 默认无参构造了
    MyClass2(const MyClass &m) {
    }
    int m_A;
};

void test02() {
    MyClass2 c1;
}

int main() {
    test01();

    // test02();

    // system("pause");
    return EXIT_SUCCESS;
}