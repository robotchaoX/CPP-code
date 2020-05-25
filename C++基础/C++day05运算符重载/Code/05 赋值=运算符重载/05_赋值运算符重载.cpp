#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

using namespace std;

//一个类默认创建时函数： 默认构造、析构、拷贝构造、operator=赋值运算符 进行简单的值传递
class Person0 {
  public:
    Person0(int a) {
        this->m_A = a;
    }

    int m_A;
};

void test01() {
    Person0 p1(1); // 堆

    Person0 p2(2); // 堆

    p2 = p1; // 默认赋值=，默认进行简单的值传递，浅拷贝

    cout << "p2 的m_A: " << p2.m_A << endl;
}

class Person {
  public:
    // 有参构造,每次构造时new空间大小不同
    // Person(char  *name) {
    // 不加const // warning: ISO C++ forbids converting a string constant to 'char*'[-Wwrite-strings]
    // C++ 不允许 "字符串" 直接转 char*,可以转 const char*
    Person(const char *name) {
        this->pName = new char[strlen(name) + 1]; // 构造时 new
        strcpy(this->pName, name);
        cout << "构造len: " << strlen(pName) + 1 << endl;
    }

    // 拷贝构造,深拷贝
    Person(const Person &p) {
        // 开辟空间
        this->pName = new char[(strlen(p.pName) + 1)];
        strcpy(pName, p.pName); // 复制数据
        cout << "深拷贝-构造len: " << strlen(pName) + 1 << endl;
    }

    //! 深拷贝,重新new申请需要的目的空间大小
    //重载 = 赋值运算符
    Person &operator=(Person &p) {
        // 先释放构造时小空间,因为每次构造时new空间大小不同
        if (this->pName != NULL) {
            delete[] this->pName;
            this->pName = NULL;
        }

        // 重新开辟目的大空间
        this->pName = new char[strlen(p.pName) + 1]; // 深拷贝
        strcpy(this->pName, p.pName);
        cout << "深拷贝-重载=len: " << strlen(pName) + 1 << endl;

        return *this; // 可c = a = b
    }

    ~Person() {
        cout << "析构len: " << strlen(pName) + 1 << endl;
        if (this->pName != NULL) {
            delete[] this->pName; // 析构时 delete
            this->pName = NULL;
        }
    }

  public:
    char *pName;
};

void test02() {
    Person p1("Devid"); // 构造new长度5+1

    // 深拷贝构造
    Person p2(p1); // 申请相同长度空间
    cout << p1.pName << endl;
    cout << p2.pName << endl;

    Person p3(""); // 构造new长度0+1
    // 重载=深拷贝,重新申请足够长度空间
    p3 = p1;
    cout << p1.pName << endl;
    cout << p3.pName << endl;
}

int main() {

    test01();

    test02();

    // system("pause");
    return EXIT_SUCCESS;
}