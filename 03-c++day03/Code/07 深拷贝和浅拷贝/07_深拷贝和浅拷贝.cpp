#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

using namespace std;

class Person {
  public:
    Person() { cout << "无参构造函数调用" << endl; }
    //初始化属性
    // Person(char  *name, int age) { // 不加const // warning: ISO C++ forbids converting a string constant to 'char*'
    // [-Wwrite-strings]
    Person(char const *name, int age) {
        m_Name = (char *)malloc(strlen(name) + 1);
        strcpy(m_Name, name);
        m_age = age;
        cout << "有参构造函数调用" << endl;
    }

    //拷贝构造 系统会提供默认拷贝构造，而且是简单的值拷贝
    //自己提供拷贝构造，原因简单的浅拷贝会释放堆区空间两次，导致挂掉
    //深拷贝
    Person(const Person &p) {
        m_age = p.m_age;
        m_Name = (char *)malloc(strlen(p.m_Name) + 1);
        strcpy(m_Name, p.m_Name);
        cout << "深拷贝构造" << endl;
    }

    ~Person() {
        cout << "析构函数调用" << endl;
        if (m_Name != NULL) {
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