#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class MyPrint {
  public:
    // () 重载
    void operator()(string text) { //
        cout << text << endl;
    }
};

void test01() {
    MyPrint myPrint;
    myPrint("hello world"); // 仿函数  // 对象();
}

class MyAdd {
  public:
    // () 重载
    int operator()(int v1, int v2) { //
        return v1 + v2;
    }
};

void test02() {
    MyAdd myAdd;
    cout << "仿函数 myAdd(1, 1) : " << myAdd(1, 1) << endl;     // 仿函数  // 对象();
    cout << "仿函数 MyAdd()(1, 1) : " << MyAdd()(1, 1) << endl; // 匿名对象  // 类();
}

int main() {

    test01();

    test02();

    // system("pause");
    return EXIT_SUCCESS;
}