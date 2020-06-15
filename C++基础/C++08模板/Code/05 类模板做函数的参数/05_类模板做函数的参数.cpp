#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

//类模板
template <class NameType, class AgeType = int> //类模板可以有默认类型
class Person {
  public:
    Person(NameType name, AgeType age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson() {
        cout << "姓名：" << this->m_Name << " 年龄： " << this->m_Age << endl;
    }

  private:
    NameType m_Name;
    AgeType m_Age;
};

// 1 指定类模板传入类型
// 全局函数
void doWork(Person<string, int> &p) { // 类模板做形参
    p.showPerson();
}

void test01() {
    Person<string, int> p("小明", 10); // 构造

    doWork(p); // 传对象
}

// 2 参数模板化
// 函数模板
template <class T1, class T2>
void doWork2(Person<T1, T2> &p) {
    // typeid查看类型
    cout << typeid(T1).name() << endl; // string
    cout << typeid(T2).name() << endl; // int
    p.showPerson();
}

void test02() {
    Person<string, int> p("呆贼", 18); // 构造

    doWork2(p); // 传对象
}

// 3 整体模板化
// 函数模板
template <class T>
void doWork3(T &p) {
    // typeid查看类型
    cout << typeid(T).name() << endl; // Person
    p.showPerson();
}

void test03() {
    Person<string, int> p("劣人", 18); // 构造

    doWork3(p); // 传对象
}

int main() {
    test01();

    test02();

    test03();

    // system("pause");
    return EXIT_SUCCESS;
}