#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Person {
  public:
    Person() {
        cout << "构造 " << endl;
    }

    void showNone() {
        cout << "Person show" << endl;
    }

    void showAge() {
        cout << this->m_Age << endl; // NULL -> m_Age
    }

    int m_Age; //
};

void test01() {
    // 对象指针,不调用构造函数
    Person *p = NULL;
    // 没有构造对象也可以访问类成员函数,类对象只存储普通类属性变量,类成员函数和类属性变量是分开存储的
    p->showNone(); // ok,不访问属性
    // p->showAge(); // error,空指针没法访问属性
}

int main() {
    test01();

    // system("pause");
    return EXIT_SUCCESS;
}