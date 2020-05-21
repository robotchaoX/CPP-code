#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

using namespace std;

class MyClass0 {
  public:
    MyClass0() {
        cout << "默认构造函数调用" << endl;
    }
    MyClass0(int a) {
        cout << "有参构造函数调用" << endl;
    }

    // 拷贝构造
    // 不手动提供拷贝构造函数
    // 系统会提供默认拷贝构造，只是是简单的值拷贝,浅拷贝

    ~MyClass0() {
        cout << "析构函数调用" << endl;
    }

  public:
    int m_Age;
};

class MyClass1 {
  public:
    MyClass1() {
        cout << "默认构造函数调用" << endl;
    }
    MyClass1(int a) {
        cout << "有参构造函数调用" << endl;
    }

    // 自己提供浅拷贝构造函数,浅拷贝
    MyClass1(const MyClass1 &p) {
        m_Age = p.m_Age;
        cout << "拷贝构造函数调用" << endl;
    }

    ~MyClass1() {
        cout << "析构函数调用" << endl;
    }

  public:
    int m_Age;
};

//* 构造函数开辟了空间,拷贝需要深拷贝,简单的浅拷贝析构会释放堆区空间两次，导致挂掉
class Person {
  public:
    Person() {
        cout << "无参构造函数调用" << endl;
    }

    // 有参构造,开辟了空间,拷贝需要深拷贝
    // Person(char  *name, int age) {
    // 不加const // warning: ISO C++ forbids converting a string constant to 'char*'[-Wwrite-strings]
    // C++ 不允许 "字符串" 直接转 char*,可以转 const char*
    Person(const char *name, int age) {
        // 开辟空间,需要深拷贝
        m_Name = (char *)malloc(strlen(name) + 1);
        strcpy(m_Name, name);
        m_age = age;
        cout << "有参构造函数调用" << endl;
    }

    //拷贝构造 系统会提供默认拷贝构造，而且是简单的值拷贝
    // 自己提供拷贝构造，
    // 原因:简单的浅拷贝会释放堆区空间两次，导致挂掉

    // 深拷贝
    // 自己提供深拷贝构造函数,深拷贝
    Person(const Person &p) {
        this->m_age = p.m_age;
        // 开辟空间
        this->m_Name = (char *)malloc(strlen(p.m_Name) + 1);
        strcpy(m_Name, p.m_Name); // 复制数据
        cout << "深拷贝构造" << endl;
    }

    ~Person() {
        cout << "析构函数调用" << endl;
        if (m_Name != NULL) {
            // 释放空间
            free(m_Name);
            m_Name = NULL;
        }
    }

    //姓名
    char *m_Name;
    //年龄
    int m_age;
};

void test01() {
    Person p1("敌法", 10);
    Person p2(p1); //调用拷贝构造
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}