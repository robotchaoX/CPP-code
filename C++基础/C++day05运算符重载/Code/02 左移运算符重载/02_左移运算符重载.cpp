#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Person {
    // 友元访问私有属性
    friend ostream &operator<<(ostream &cout, Person &p1);

  public:
    Person() {
    }
    Person(int a, int b) {
        this->m_A = a;
        this->m_B = b;
    }

    //重载左移<<运算符不可以写到成员函数中,只能利用全局函数 进行 << 运算符的重载
    // void operator<<() { // error
    // }

  private:
    int m_A;
    int m_B;
};

// 只能利用全局函数 进行 << 运算符的重载
// 返回类型 ostream &,第一个参数 cout  第二个参数  p1
ostream &operator<<(ostream &cout, Person &p1) { // 全局 operator<<(cout,p1)
    // 插入到输出流cout
    cout << "m_A = " << p1.m_A << ", m_B = " << p1.m_B;

    return cout; // 返回输出流cout的引用
}

void test01() {
    Person p1(10, 10);

    cout << "+++ " << p1 << " +++" << endl;

    cout << "---" << endl;
    // operator<<()函数原型调用
    operator<<(cout, p1);
    cout << "---" << endl;
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}