#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Base {
  public:
    int m_A_pub;

  protected:
    int m_B_pro;

  private:
    int m_C_pri;
};

/////////////////////公有继承/////////////////////
// public公有继承
class Son1 : public Base {
  public:
    void func() {
        // cout << m_C_pri << endl; //基类中私有的属性 不可继承
        cout << m_A_pub << endl; //基类中公有的属性 可继承，还是public
        cout << m_B_pro << endl; //基类中保护的属性 可继承，还是protected 类外访问不到
    }
};
void myFunc1() {
    Son1 s1;
    s1.m_A_pub;
    // s1.m_B_pro; // 类外无法访问protected属性
}

/////////////////////保护继承/////////////////////
// protected保护继承
class Son2 : protected Base {
  public:
    void func() {
        // cout << m_C_pri << endl; //基类中私有的属性 不可继承
        cout << m_A_pub << endl; //基类中公有的属性 可继承，还是protected
        cout << m_B_pro << endl; //基类中保护的属性 可继承，还是protected
    }
};
void myFunc2() {
    Son2 s2;
    // s2.m_A_pub; // 类外无法访问protected属性
}

/////////////////////私有继承/////////////////////
// private私有继承
class Son3 : private Base {
  public:
    void func() {
        // cout << m_C_pri << endl; //基类中私有的属性 不可继承
        cout << m_A_pub << endl; //基类中公有的属性 可继承，还是private
        cout << m_B_pro << endl; //基类中保护的属性 可继承，还是private
    }
};
void myFunc3() {
    Son3 s3;
    // s3.m_A_pub; // 类外无法访问private属性
}

class GrandSon3 : public Son3 {
  public:
    void myFunc() {
        // cout << m_A_pub << endl; //孙子类中 访问不到 m_A_pub，因为在Son3中m_A_pub已经是私有属性了
    }
};

int main() {
    myFunc1();

    myFunc2();

    myFunc3();

    // system("pause");
    return EXIT_SUCCESS;
}