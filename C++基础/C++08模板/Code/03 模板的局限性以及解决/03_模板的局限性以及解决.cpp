#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Person {
  public:
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }

  public:
    string m_Name;
    int m_Age;
};

template <class T>
bool myCompare(T &a, T &b) { // 传自定义数据类型不行
    if (a == b) {
        return true;
    }
    return false;
}

// 通过第三代具体化自定义数据类型，解决上述问题
// 如果具体化能够优先匹配，那么就选择具体化
// 语法  template<>
//      返回值  函数名<具体类型>(参数)
// 比较自定义类型Person,(模板的写法??)
template <> // 不用通用类型class T,下面具体指定，此处空类型<>
bool myCompare<Person>(Person &a, Person &b) { // 具体指定<Person>自定义类型 // 重载
    if (a.m_Age == b.m_Age) {
        return true;
    }

    return false;
}

void test01() {
    int a = 10;
    int b = 20;
    // 普通模板template <class T>
    int ret = myCompare(a, b);
    cout << "ret = " << ret << endl;

    Person p1("Tom", 10);
    Person p2("Jerry", 10);
    // 具体化自定义数据类型模板template <>
    int ret2 = myCompare(p1, p2);
    cout << "ret2 = " << ret2 << endl;
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}