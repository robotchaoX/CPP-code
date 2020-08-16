// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

namespace KingGlory {
int sunwukongId = 10;
int A = 10;
} // namespace KingGlory

void test01() {
    int sunwukongId = 20; // 重名变量

    // using 声明  需注意避免二义性问题
    //写了using声明后 下面这行代码说明以后看到的sunwukongId 是用KingGlory下的
    //但是可能会与重名变量冲突

    //产生二义性
    // using KingGlory::sunwukongId; // error与重名变量冲突

    cout << sunwukongId << endl;
}

namespace cv {
int Mat = 11;
int Rect = 44;
} // namespace cv

namespace sl {
int Mat = 88;
int Rect = 99;
} // namespace sl

void test02() {
    // using编译指令
    // using 使用命名空间某一变量
    using cv::Mat;
    cout << Mat << endl;
    // cout << Rect << endl; // error

    // using 使用命名空间所有变量
    using namespace cv;
    cout << Mat << endl;
    cout << Rect << endl;

    using namespace sl;
    //指明命名空间，避免二义性问题
    cout << cv::Mat << endl;
    cout << sl::Mat << endl;
}

// 使用using定义类型的别名
void test03() {
    // 定义类型的别名
    typedef int points_t;
    using points_u = int; //等价的写法
    // using 别名 = xxx(类型）;

    // 定义诸如函数指针等类型
    typedef void (*FP)(int, const std::string &);
    using FP = void (*)(int, const std::string &); //等价的using别名
}

// using可以在模板别名中使用，但是typedef不可以
template <typename T>
using Vec = MyVector<T, MyAlloc<T>>;

// usage
Vec<int> vec;

int main() {

    test01();

    test02();

    test03();

    return EXIT_SUCCESS;
}