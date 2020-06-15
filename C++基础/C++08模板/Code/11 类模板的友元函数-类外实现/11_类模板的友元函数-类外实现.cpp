#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

//让编译器看到Person类声明
template <class T1, class T2>
class Person; // 前向声明

// 声明函数模板
//让编译器提前看到printPerson声明
template <class T1, class T2>
void printPerson(Person<T1, T2> &p); // 前向声明

// 类模板
template <class T1, class T2>
class Person {
    // 友元函数类外实现
    // 利用空参数列表<> 告诉编译器 模板函数的声明
    friend void printPerson<>(Person<T1, T2> &p); // 普通函数 声明

  public:
    Person(T1 name, T2 age) {
        this->m_Name = name;
        this->m_Age = age;
    }

  private:
    T1 m_Name;
    T2 m_Age;
};

// 友元函数模板 类外实现
template <class T1, class T2>
void printPerson(Person<T1, T2> &p) {
    cout << "姓名：" << p.m_Name << "  年龄： " << p.m_Age << endl;
}

void test01() {
    Person<string, int> p("Tom", 10);

    // 友元函数,全局函数
    printPerson(p);
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}