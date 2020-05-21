#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Person {
  public:
    // 无参构造
    Person() {
        ;
    };

    // 初始化列表 默认数据数据
    Person(int a) : m_B(33), m_C(33) {
        ;
    }

    Person(int a, int b) : m_A(a), m_B(b) {
        ;
    }
    //有参构造初始化数据
    // Person(int a, int b, int c) {
    //     m_A = a;
    //     m_B = b;
    //     m_C = c;
    // }

    // 参数默认值
    //利用初始化列表 初始化数据
    // 构造函数后面  +  : 属性（参数）, 属性（参数）...
    Person(int a, int b, int c, int def = 4) : m_A(a), m_B(b), m_C(c), m_default(def) {
        ;
    }

  public:
    int m_A;
    int m_B;
    int m_C;
    int m_no_init; // 未初始化,默认随机值？？
    int m_y_init = -1; // c++11类属性可以设置初始值
    // 在C++11中，大多数的基础数据类型都可以直接初始化，可以不通过构造函数来初始化
    int m_default;
};

void test00() {
    Person p1;
    cout << "p1的m_A :" << p1.m_A << endl;
    cout << "p1的m_B :" << p1.m_B << endl;
    cout << "p1的m_no_init :" << p1.m_no_init << endl;
    cout << "p1的m_y_init :" << p1.m_y_init << endl;

    Person p2(1, 2, 3);
    cout << "p2的m_A :" << p2.m_A << endl;
    cout << "p2的m_B :" << p2.m_B << endl;
    cout << "p2的m_no_init :" << p2.m_no_init << endl;
    cout << "p1的m_y_init :" << p1.m_y_init << endl;
}

struct Point {
    int x;
    int y;
};
void test01() {

    int a0 = 3;
    int a1 = {3};
    int a2{3}; // 初始化表

    Person p1(1);
    Person p2{2}; //! 初始化表,有参构造
    Person p3 = {3}; // 隐式转换,初始化表??
    Person p4(p1);
    Person p5{p1}; // 初始化表,拷贝构造
    Person p6 = {p1}; // 隐式转换,初始化表??

    int arr_1[3] = {1, 2, 3};
    int arr_2[] = {1, 3, 2, 4};
    int arr_3[]{1, 3, 2, 4}; // 初始化表

    // 初始化struct结构体
    Point p = {1, 2}; // 初始化表

    struct A {
        int x;
        int y;
    } a_s = {1, 2}; // 初始化表

    // Vector 接收了一个初始化列表
    vector<int> v1 = {1, 2, 3};
    vector<int> v2{1, 2, 3}; // 初始化表
    vector<string> vs1 = {"foo", "bar"};
    vector<string> vs2{"foo", "bar"};
    // 不考虑细节上的微妙差别，大致上相同。

    // new 时初始化
    vector<int> *vec_ptr1 = new vector<int>{1, 2, 3}; // 初始化表
    vector<int> *vec_ptr2 = new vector<int>({1, 2, 3}); // ??
    auto vec_ptr3 = new vector<string>{"foo", "bar"};
    auto vec_ptr4 = new vector<string>({"foo", "bar"}); // ??

    // map 接收了一些 pair, 列表初始化大显神威。
    map<int, string> m = {{1, "one"}, // 初始化表
                          {2, "2"}};

    // for遍历初始化列表
    for (int elem : {-1, -2, -3}) {
        ;
    }
}

class Foo {
  public:
    Foo(int) {
    }

  private:
    Foo(const Foo &); // 限制拷贝构造
};
//  C++11 初始化列表
void test02() {
    Foo a1(123);
    // Foo a2 = 123; // error: 'Foo::Foo(const Foo &)' is private

    Foo a3 = {123}; // 初始化列表
    Foo a4{123}; // 初始化列表

    // 基本数据类型的列表初始化方式
    int a5 = {3};
    int a6{3};
}

// c++11类属性可以设置初始值
class MyClass {
  public:
    int no_init; // 未初始化是随机值
    int y_init = -1; // c++11类属性可以设置初始值
    // 在C++11中，大多数的基础数据类型都可以直接初始化，可以不通过构造函数来初始化

    static const int a = 1;
    const double b = 2.2;
    //为了保持静态属性成员是属于整个类的，C++11的做法和以前一样，依旧在类外定义并初始化
    static int static_y_init; //声明c,必须类外初始化
    double d = 4.4;

    char str[33] = "Hello World!";
    int num[10] = {-2};

  private:
};
int MyClass::static_y_init = 3; //在这里定义并初始化

void test03() {
    MyClass C;
    cout << C.no_init << endl;
    cout << C.y_init << endl;
    cout << C.a << endl;
    cout << C.b << endl;
    cout << C.static_y_init << endl;
    cout << C.d << endl;
    cout << C.str << endl;
    cout << C.num[3] << endl;
}

// 在函数调用里用列表初始化
// 形参为vector
void TestFunction2(vector<int> v) {
}
void test04() {

    // 函数调用 列表初始化
    TestFunction2({1, 2, 3});

    // 实际是 vector<int> v = {1, 2, 3}; ??
}

// 初始化列表也可以用在返回类型上的隐式转换
// 返回值为vector
vector<int> test_function() {
    // 返回类型初始化列表
    return {1, 2, 3};
}

int main() {
    test00();
    test01();
    test02();
    test03();
    test04();

    // system("pause");
    return EXIT_SUCCESS;
}