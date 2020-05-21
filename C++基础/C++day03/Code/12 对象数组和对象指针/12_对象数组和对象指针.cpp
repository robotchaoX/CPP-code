#include <cstring>
#include <iostream>
#include <string>

using namespace std;

class Person {
  public:
    Person() {
        cout << "无参构造" << endl;
    }

    Person(string name, int age) {
        m_Name = name;
        m_age = age;
        cout << "有参构造" << endl;
    }

    Person(const Person &p) {
        this->m_Name = p.m_Name;
        this->m_age = p.m_age;
        cout << "拷贝构造" << endl;
    }

    ~Person() {
        cout << "析构函数调用" << endl;
    }

  public:
    string m_Name; //姓名
    int m_age; //年龄
};

void test01() {
    // 定义对象时,会构造对象
    Person p0; // 默认构造
    Person p1("敌法", 10); // 有参构造
    Person p2(p1); //调用拷贝构造
}

void test02() {
    // 定义对象数组时,会分配空间,会构造对象
    Person per_arr[3]; // 默认构造
}

void test03() {
    // 定义对象数组时，直接初始化对象，只发生一次初始化有参的构造
    Person per[3] = {Person(), Person("小明", 22), Person("老王", 55)};
}

void test04() {
    Person p0; // 默认构造
    Person p1("敌法", 10); // 有参构造
    Person p2(p1); //调用拷贝构造
    cout << "-------" << endl;

    // 定义对象数组时,会构造对象
    Person per[3] = {p0, p1, p2}; // 通过拷贝构造复制的对象
    cout << "-------" << endl;
}

void test05() {
    // 定义对象时,会构造对象
    Person per; // 默认构造

    //! 定义对象数组时,会分配空间,会构造对象
    Person per_arr[3]; // 默认构造3次
}

void test06() {
    //! 定义对象指针时，不会构造对象
    Person *per_ptr; // 只分配指针的空间，不分配对象空间

    //! 定义对象指针数组时,只分配指针的空间，不会构造对象
    Person *per_ptrArr[3]; // 只分配指针的空间，不分配对象空间
}

void test07() {
    Person p0; // 默认构造
    Person p1("敌法", 10); // 有参构造
    Person p2(p1); //调用拷贝构造
    cout << "-------" << endl;

    // 只分配指针的空间，不分配对象空间
    Person *per_ptrArr[3] = {&p0, &p1, &p2}; // 传对象的地址
    cout << "-------" << endl;

    cout << "指针调用 per_ptrArr[2]->m_age：" << per_ptrArr[2]->m_age << endl;
}

int main() {

    // test01();

    // test02();

    // test03();

    // test04();

    // test05();

    // test06();

    test07();

    // system("pause");
    return EXIT_SUCCESS;
}