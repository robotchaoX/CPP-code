// #define _CRT_SECURE_NO_WARNINGS
#include "game1.h"
#include "game2.h"
#include <iostream>

using namespace std;

// namespace命名空间主要用途 用来解决命名冲突的问题
namespace LOL {
void goAtk(); // 函数声明
}
// 函数实现
void LOL::goAtk() {
    cout << "LOL攻击实现" << endl;
}

namespace KingGlory {
void goAtk(); // 函数声明
}
// 函数实现
void KingGlory::goAtk() {
    cout << "王者农药攻击实现" << endl;
}

void test01() {
    LOL::goAtk();
    KingGlory::goAtk();
}

// 1、命名空间下 可以放函数、变量、结构体、类
namespace A {
void func(); // 函数
int m_A = 20; // 变量
struct Person {}; // 结构体
class Animal {}; // 类

// 命名空间嵌套
namespace innerB {
int m_A = 10; // 重名变量
}
}

// 2、命名空间必须定义在全局作用域下
// 3、命名空间可以嵌套命名空间

void test02() {
    cout << "作用域B下的m_A为： " << A::innerB::m_A << endl;
}

// 4、命名空间是开放的，可以随时往原先的命名空间添加内容
namespace A { //此A命名空间会和上面的命名空间A进行合并
int m_B = 1000;
}

void test03() {
    cout << "A::下的m_A为" << A::m_A << " m_B为： " << A::m_B << endl;
}

// 5、无名、匿名命名空间
namespace {
int m_C = 0;
int m_D = 0;
} // namespace
//当写了无名命名空间，相当于写了 static int m_C ; static int m_D;
//只能在当前文件内使用

// 6、命名空间可以起别名
namespace veryLongName_____ {
int m_A = 0;
}
void test04() {
    //起别名
    namespace veryShortName = veryLongName_____; // 命名空间赋值，起别名
    cout << veryLongName_____::m_A << endl;
    cout << veryShortName::m_A << endl;
}

namespace cv {
int Mat = 11;
int Rect = 44;
}
void test00() {

    // using 使用命名空间某一变量
    using cv::Mat;
    cout << Mat << endl;
    // cout << Rect << endl;

    // using 使用命名空间所有变量
    using namespace cv;
    cout << Mat << endl;
    cout << Rect << endl;
}

int main() {

    test01();

    test02();

    test03();

    test04();

    test00();

    return EXIT_SUCCESS;
}