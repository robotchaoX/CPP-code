#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person {
  public:
    Person() {
        cout << "默认构造函数调用" << endl;
    }
    Person(int a) {
        m_Age = a;
        cout << "有参构造函数调用" << endl;
    }
    // 拷贝构造函数
    Person(const Person &p) {
        m_Age = p.m_Age;
        cout << "拷贝构造函数调用" << endl;
    }

    ~Person() {
        cout << "析构函数调用" << endl;
    }

  public:
    int m_Age;
};

// 拷贝构造调用的时机
// 1、用已经创建好的对象来初始化新的对象
void test01() {
    cout << "--p1---" << endl;
    Person p1; // 默认构造
    p1.m_Age = 10;

    cout << "--p2---" << endl;
    Person p2(p1); //　括号法，拷贝构造

    cout << "--p3---" << endl;
    Person p3 = Person(p1); // 显式法，拷贝构造

    cout << "--p4---" << endl;
    Person p4 = p1; // 隐式转换，拷贝构造　
    // 相当于　Person p4 = Person(p1);  // Person p4(p1);

    cout << "--p5---" << endl;
    Person p5 = Person(10); //只有一次有参构造

    cout << "--------------------" << endl;
}

// 2、以值传递的方式给函数参数传值
// 值传递，临时内存会发生拷贝构造
void doWork(Person p1) { // 拷贝 Person p1 = Person(p)
    ;
}

void test02() {
    Person p;

    doWork(p); // 值传递,拷贝构造
}

// 3、以值方式返回局部对象
Person doWork2() {
    Person p1; // 默认构造
    cout << "return时拷贝" << endl; //？？
    return p1; // return时拷贝??被优化了？？
}

void test03() {
    Person p; // 默认构造
    p = doWork2(); // 局部变量对象

    cout << "-----" << endl;

    Person p2 = doWork2(); // 局部变量对象
}
// Release下优化成什么样？不拷贝，只有一次默认构造
/* Person p; 不调用默认构造
        doWork2(p);
        void doWork2(Person & p)
        {
                Person p1 //调用默认构造
        }

*/

int main() {

    // test01();

    // test02();

    test03();

    // system("pause");
    return EXIT_SUCCESS;
}