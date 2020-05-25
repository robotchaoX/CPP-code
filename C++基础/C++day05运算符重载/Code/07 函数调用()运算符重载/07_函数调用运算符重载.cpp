#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class MyPrint {
  public:
    // () 重载 ,仿函数,函数对象
    void operator()(string text) { //
        cout << text << endl;
    }
};
void test01() {
    MyPrint print;
    print("hello world"); // 仿函数  // 对象();
}

class MyAdd {
  public:
    // () 重载 ,仿函数,函数对象
    int operator()(int v1, int v2) { //
        return v1 + v2;
    }
};
void test02() {
    MyAdd myadd;
    cout << "仿函数 myAdd(1, 1) : " << myadd(1, 1) << endl; // 仿函数  // 对象();
    cout << "匿名对象 仿函数 MyAdd()(1, 1) : " << MyAdd()(1, 1) << endl; // 无参匿名对象,类名();
}

int main() {

    test01();

    test02();

    // system("pause");
    return EXIT_SUCCESS;
}