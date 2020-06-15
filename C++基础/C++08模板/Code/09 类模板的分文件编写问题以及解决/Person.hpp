#pragma once
#include <iostream>
#include <string>

using namespace std;

// 类模板声明
template <class T1, class T2>
class Person {
  public:
    Person(T1 name, T2 age);

    void showPerson();

  public:
    T1 m_Name;
    T2 m_Age;
};

// 类模板实现
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) { // 类<>也必须声明类型
    this->m_Name = name;
    this->m_Age = age;
}

// 类模板实现
template <class T1, class T2> // 每个方法都要声明template
void Person<T1, T2>::showPerson() { // 类<>也必须声明类型
    cout << "姓名：" << this->m_Name << "  年龄：  " << this->m_Age << endl;
}
