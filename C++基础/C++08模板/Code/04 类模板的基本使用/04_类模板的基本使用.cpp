#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

// 类模板
template <class NameType, class AgeType = int> //类模板可以有默认类型
class Person_T {
  public:
    Person_T(NameType name, AgeType age) {
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

void test01() {
    // 类模板 不支持 自动类型推导,必须显示指定类型
    // Person_T p("孙悟空", 100); // error 类模板 不支持 自动类型推导

    // 类模板 显示指定类型
    Person_T<string, int> p("孙悟空", 100); // 类模板 显示指定类型
    p.showPerson();
}

// 类模板
template <class T>
class myClass_T {
  public:
    // 类模板中成员函数,一开始不会创建出来,而是在运行调用时才去创建,不存在的方法不调用不创建也不报错
    void func1() {
        obj.showPerson1();
    }
    void func2() {
        obj.showPerson2();
    }

  private:
    T obj;
};

class Person1 {
  public:
    void showPerson1() {
        cout << "Person1的调用" << endl;
    }
};

class Person2 {
  public:
    void showPerson2() {
        cout << "Person2的调用" << endl;
    }
};

void test02() {
    myClass_T<Person1> m1;
    m1.func1(); // ok
    // m.func2(); // error Person1没有这个方法
    // 类模板中成员函数,一开始不会创建出来,而是在运行调用时才去创建,不存在的方法不调用不创建也不报错

    myClass_T<Person2> m2;
    // m.func1(); // error Person2没有这个方法
    m2.func2(); // ok
}

int main() {

    // test01();

    test02();

    // system("pause");
    return EXIT_SUCCESS;
}