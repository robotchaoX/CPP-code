#pragma once
#include <iostream>
#include <string>

using namespace std;

// 类模板的分文件编写,头文件声明,源文件实现类模板

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
