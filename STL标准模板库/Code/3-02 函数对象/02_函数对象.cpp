#include <iostream>
using namespace std;

// 函数对象，仿函数
class MyPrint {
  public:
    // 重载()
    void operator()(int num) {
        cout << "num " << num << endl;
        count++;
    }

  public:
    int count = 0; // c++11定义属性时可以直接初始化
};

// 全局函数
void funcPrint(int num) {
    cout << "num " << num << endl;
}

void test01() {
    // MyPrint是一个类 ，而不是函数
    MyPrint pt; // 类对象
    // 函数对象（仿函数）
    pt(111);
    // 匿名对象的函数对象（仿函数）
    MyPrint()(222); // MyPrint() 匿名对象，MyPrint()(222)函数对象（仿函数）

    funcPrint(333); // 普通函数
}

//函数对象超出普通函数概念，内部可以保存状态
void test02() {
    MyPrint pt; // 类对象
    cout << "pt使用次数：" << pt.count << endl;
    pt(111);
    pt(111);
    pt(111);
    pt(111);

    cout << "pt使用次数：" << pt.count << endl;
}

//函数对象作为参数
void doPrint(MyPrint pt, int num) {
    pt(num);
}

void test03() {
    MyPrint pt; // 类对象
    // 传对象
    doPrint(pt, 10);
    // 传匿名对象，类名()
    doPrint(MyPrint(), 20); // MyPrint() 匿名对象,是对象
}

int main() {

    test01();

    test02();

    test03();

    return EXIT_SUCCESS;
}