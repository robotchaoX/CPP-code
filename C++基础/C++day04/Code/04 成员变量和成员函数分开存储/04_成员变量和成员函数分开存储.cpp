#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class EmptyClass {
    ;
};

class MyClass {
  public:
    int m_A; // 4字节
    double m_C; // 8字节,实际会字节对齐
};
void test01() {
    //空类的大小为 1 ,每个实例的对象 都有独一无二的地址，char维护这个地址
    cout << "sizeof(EmptyClass) = " << sizeof(EmptyClass) << endl;

    // 4字节+8字节 -> 8字节+8字节  (字节对齐)
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(double) = " << sizeof(double) << endl;
    cout << "sizeof(MyClass) = " << sizeof(MyClass) << endl;

    cout << "----" << endl;
}

class Person {
  public:
    Person() {
        cout << "构造 " << endl;
    }

    //非静态成员函数,不属于对象身上
    // 编译器会偷偷加入 形参this指针 (Person * this) ??
    void func() {
        ;
    };
    //静态成员变量，不属于对象身上
    static int m_B;
    //静态成员函数，不属于对象身上
    static void func2() {
        ;
    };

  private:
    //非静态成员变量，属于对象身上
    int m_A; // 4字节
    double m_C; // 8字节,实际会字节对齐
};

// 成员变量和成员函数分开存储
void test02() {
    // 类对象只包含普通非静态属性变量,
    // 而成员函数,静态成员属性,静态成员函数分开存储,不属于类对象
    // 4字节+8字节 -> 8字节+8字节  (字节对齐)
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(double) = " << sizeof(double) << endl;
    cout << "sizeof(Person) = " << sizeof(Person) << endl;
}

void test03() {
    // this指针指向被调用的成员函数所属的对象
    Person p1;
    p1.func(); // 编译器会偷偷 加入一个 this指针  Person * this

    Person p2;
    p2.func();
}

void test04() {
    // 对象指针,不调用构造函数
    Person *p = NULL;
    // 没有构造对象也可以访问类成员函数,类对象只存储普通类属性变量,类成员函数和类属性变量是分开存储的
    p->func(); // ok,不访问属性,不需要构造对象
}

int main() {
    test01();
    test02();
    test03();
    test04();

    // system("pause");
    return EXIT_SUCCESS;
}