#include <cstring> // C 的strcp C字符串操作
#include <iostream>
#include <string> // C++ 的string类型

using namespace std;

class Person {
  public:
    //设置年龄
    void setAge(int age) {
        m_Age = age;
    }

    //获取年龄 读权限
    int getAge() {
        return m_Age;
    }

    int getHeight() {
        return m_Height;
    }

    //读姓名
    string getName() {
        return m_Name;
    }

    //写姓名
    void setName(string name) {
        m_Name = name;
    }

    //只写的情人
    void setLover(string lover) {
        m_lover = lover;
    }

  private: //类外不可访问，类内可以访问
    // 在C++11中，大多数的基础数据类型都可以直接初始化，可以不通过构造函数来初始化
    int m_Age = -1; // c++11类属性可以设置初始值
    int m_Height; // 未初始化默认0？？

    string m_Name; //公有权限  读写
    string m_lover; //情人  只写
};

void test01() {
    Person p1;
    cout << "p1的身高：" << p1.getHeight() << endl; // 类属性初始值
    cout << "p1的年龄：" << p1.getAge() << endl; // 类属性初始值

    p1.setName("老王");
    cout << "p1的姓名：" << p1.getName() << endl;

    //年龄
    p1.setAge(20);

    cout << "p1的年龄：" << p1.getAge() << endl;

    //情人 只能设置 外部我不告诉你
    p1.setLover("仓井");
}

int main() {

    test01();

    return EXIT_SUCCESS;
}