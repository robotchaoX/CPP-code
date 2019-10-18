#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyPrint {
  public:
    void operator()(int num) {
        cout << "num " << num << endl;
        count++;
    }
    int count = 0;
};

void funcPrint(int num) { cout << "num " << num << endl; }

void test01() {
    // MyPrint是一个类 ，而不是函数
    MyPrint myPrint; // 类对象
    myPrint(111); // 函数对象（仿函数）
    MyPrint()(1000); // MyPrint() 匿名对象，MyPrint()(1000)对象函数

    // funcPrint(111); // 普通函数
}

//函数对象超出普通函数概念，内部可以保存状态
void test02() {
    MyPrint myPrint;
    myPrint(111);
    myPrint(111);
    myPrint(111);
    myPrint(111);

    cout << "myPrint使用次数：" << myPrint.count << endl;
}

//函数对象作为参数
void doPrint(MyPrint print, int num) { //
    print(num);
}
void test03() { //
    doPrint(MyPrint(), 20); // MyPrint() 匿名对象,是对象
}

int main() {

    // test01();

    // test02();

    test03();

    // system("pause");
    return EXIT_SUCCESS;
}