#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Person {
    //友元函数类内实现
    friend void printPerson(Person<T1, T2> &p) {
        cout << "姓名：" << p.m_Name << "  年龄： " << p.m_Age << endl;
    }

  public:
    Person(T1 name, T2 age) {
        this->m_Name = name;
        this->m_Age = age;
    }

  private:
    T1 m_Name;
    T2 m_Age;
};

void test01() {
    Person<string, int> p("Tom", 10);
    printPerson(p);
}

int main() {
    test01();

    // system("pause");
    return EXIT_SUCCESS;
}