// #define _CRT_SECURE_NO_WARNINGS
#include "game1.h"
#include "game2.h"
#include <iostream>

using namespace std;

// 0、namespace命名空间主要用来解决命名冲突的问题
namespace LOL {
void sameNameFunc(); // 函数声明
}
// 函数实现
void LOL::sameNameFunc() {
    cout << "LOL攻击实现" << endl;
}

namespace KingGlory {
void sameNameFunc(); // 函数声明
}
// 函数实现
void KingGlory::sameNameFunc() {
    cout << "王者农药攻击实现" << endl;
}

void test01() {
    LOL::sameNameFunc();
    KingGlory::sameNameFunc();
}

// 1、命名空间下 可以放函数、变量、结构体、类
// 2、命名空间必须定义在全局作用域下
namespace A {
void func(); // 函数
int m_Val = 20; // 变量
struct Person {}; // 结构体
class Animal {}; // 类

// 3、命名空间可以嵌套命名空间
// 命名空间嵌套
namespace innerB {
int m_Val = 11; // 重名变量
}
} // namespace A

void test02() {
    cout << "作用域A下的 m_Val 为： " << A::m_Val << endl;
    cout << "作用域B下的 m_Val 为： " << A::innerB::m_Val << endl;
}

// 4、命名空间是开放的，可以随时往原先的命名空间添加内容
namespace A { //此A命名空间会和上面的命名空间A进行合并
int m_Val_added = 1000;
}

void test03() {
    cout << "A::下的 m_Val 为: " << A::m_Val << endl;
    cout << "A::下的 m_Val_added 为：" << A::m_Val_added << endl;
}

// 命名空间内函数声明和实现可分离
namespace MySpace {
void func1(); // 仅函数声明
void func2(int param);
} // namespace MySpace
void MySpace::func1() { // 函数实现
    cout << "MySpace::func1" << endl;
}
void MySpace::func2(int param) {
    cout << "MySpace::func2 : " << param << endl;
}

// 5、无名、匿名命名空间
// 当写了无名命名空间，相当于写了 static 只能在当前文件内使用
namespace {
int a = 10;
void func() {
    cout << "hello namespace" << endl;
}
} // namespace

void test04() {
    cout << "a : " << a << endl;
    func();
}

// 6、命名空间可以起别名
namespace very__Long__Name {
int m_A = 0;
}
void test05() {
    //起别名
    namespace shortName = very__Long__Name; // 命名空间赋值，起别名
    cout << very__Long__Name::m_A << endl;
    cout << shortName::m_A << endl;
}

namespace cv {
int Mat = 11;
int Rect = 44;
} // namespace cv

// 7、using声明
void test07() {
    // using 使用命名空间某一变量
    using cv::Mat;
    cout << Mat << endl;
    // cout << Rect << endl;

    // using 使用命名空间所有变量
    using namespace cv;
    cout << Mat << endl;
    cout << Rect << endl;
}

// 如果命名空间包含重载的函数，using声明就声明了这个重载函数的所有
namespace overLoad {
void func() {
}
void func(int x) {
}
int func(int x, int y) {
}
} // namespace overLoad
void test08() {
    using overLoad::func;
    func();
    func(10);
    func(10, 20);
}

int main() {

    test01();

    test02();

    test03();

    test04();

    test05();

    test07();

    test08();

    return EXIT_SUCCESS;
}