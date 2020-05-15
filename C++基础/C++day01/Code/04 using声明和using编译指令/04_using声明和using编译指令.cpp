// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

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

namespace KingGlory {
int sunwukongId = 10;
int A = 10;
}
void test01() {
    int sunwukongId = 20; // 重名变量

    // using 声明  需注意避免二义性问题
    //写了using声明后 下面这行代码说明以后看到的sunwukongId 是用KingGlory下的
    //但是可能会与重名变量冲突

    //产生二义性
    // using KingGlory::sunwukongId; // 与重名变量冲突

    cout << sunwukongId << endl;
}

// using编译指令
namespace LOL {
int sunwukongId = 30;
}

void test02() {
    // int sunwukongId = 20;
    // using编译指令
    using namespace KingGlory; //打开王者荣耀房间
    using namespace LOL; //打开LOL房间
    //如果打开多个房间，也要避免二义性问题
    // cout << sunwukongId << endl; // 产生二义性
    cout << KingGlory::sunwukongId << endl;
    cout << LOL::sunwukongId << endl;
}

int main() {

    test00();

    test01();

    test02();

    return EXIT_SUCCESS;
}