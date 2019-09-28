#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;

//一个类默认创建时函数： 默认构造、析构、拷贝构造、operator=赋值运算符 进行简单的值传递
class Person {
  public:
    Person(int a) { this->m_A = a; }

    int m_A;
};

void test01() {
    Person p1(10);

    Person p2(0);

    p2 = p1; //默认赋值，默认进行简单的值传递，浅拷贝

    cout << "p2 的m_A" << p2.m_A << endl;
}

class Person2 {
  public:
    // 有参构造
    Person2(char *name) {
        this->pName = new char[strlen(name) + 1]; // 构造时 new
        strcpy(this->pName, name);
    }

    //重载 = 赋值运算符
    Person2 &operator=(Person2 &p) {
        // 判断如果原来已经堆区有内容，先释放
        if (this->pName != NULL) {
            delete[] this->pName;
            this->pName = NULL;
        }

        // 重新开辟
        this->pName = new char[strlen(p.pName) + 1];
        strcpy(this->pName, p.pName);

        return *this; // 可c = a = b
    }

    ~Person2() {
        if (this->pName != NULL) {
            delete[] this->pName; // 析构时 delete
            this->pName = NULL;
        }
    }

    char *pName;
};

void test02() {
    Person2 p1("狗蛋");

    Person2 p2("狗剩");

    Person2 p3("");
    p2 = p1; //默认赋值，默认进行简单的值传递，浅拷贝?? 未重载=也并没有报错？？
    p3 = p2 = p1;

    cout << p1.pName << endl;
    cout << p2.pName << endl;
    cout << p3.pName << endl;

    // int a = 10;
    // int b = 20;
    // int c;
    // c = a = b; //都是20
    // cout << a << " " << b << " " << c << endl;
}

int main() {

    // test01();

    test02();

    // system("pause");
    return EXIT_SUCCESS;
}