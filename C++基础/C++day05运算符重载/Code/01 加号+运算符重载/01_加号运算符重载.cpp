#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Person {
  public:
    Person(){};
    Person(int a, int b) : m_A(a), m_B(b) {
    }

    //利用类方法 进行-号运算符的重载
    //-号运算符重载 成员函数 二元
    Person operator-(Person &p) { //二元,只传一个参数即可 类方法 p1.operator+(p2)
        Person tmp;
        tmp.m_A = this->m_A - p.m_A;
        tmp.m_B = this->m_B - p.m_B;
        return tmp; // 返回 值
    }

    //-号运算符的重载 重载的版本
    Person operator-(int a) { //二元,只传一个参数即可 类方法 p1.operator-(p2)
        Person tmp;
        tmp.m_A = this->m_A - a;
        tmp.m_B = this->m_B - a;
        return tmp;
    }

    int m_A;
    int m_B;
};

//利用全局函数 进行 + 号运算符的重载
Person operator+(Person &p1, Person &p2) { //二元,二个参数 全局函数 operator+(p1,p2)
    Person tmp;
    tmp.m_A = p1.m_A + p2.m_A;
    tmp.m_B = p1.m_B + p2.m_B;
    return tmp; // 返回 值
}

//全局函数 +号运算符的重载 重载的版本
Person operator+(Person &p1, int a) { //二元,二个参数 全局函数 operator+(p1,p2)
    Person tmp;
    tmp.m_A = p1.m_A + a;
    tmp.m_B = p1.m_B + a;
    return tmp;
}

void test01() {
    Person p1(10, 10);
    Person p2(20, 20);

    // 对象+调用
    Person p3 = p1 + p2; // p1+p2 从operator+(p1,p2)表达式转变的？
    Person p4 = p1 + 3; //重载的版本
    cout << "p3 的 m_A: " << p3.m_A << "  m_B: " << p3.m_B << endl;
    cout << "p4 的 m_A: " << p4.m_A << "  m_B: " << p4.m_B << endl;

    // operator+()函数原型调用
    Person p5 = operator+(p1, p2);
    Person p6 = operator+(p1, 3);
    cout << "p5 的 m_A: " << p5.m_A << "  m_B: " << p5.m_B << endl;
    cout << "p6 的 m_A: " << p6.m_A << "  m_B: " << p6.m_B << endl;

    // 减法
    Person p7 = p1 - p2; // p1-p2 从operator-(p1,p2)表达式转变的？(p2)  operator+(p1,p2)
    Person p8 = p1 - 3; //重载的版本
    cout << "p7 的 m_A: " << p7.m_A << "  m_B: " << p7.m_B << endl;
    cout << "p8 的 m_A: " << p8.m_A << "  m_B: " << p8.m_B << endl;
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}