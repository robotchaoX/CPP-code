#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//宏定义一个加法
#define MyAdd(x, y) x + y // 不加括号有问题((x) + (y))

// 宏定义缺陷，简单替换
void test01() {
    int ret = MyAdd(10, 20) * 20; //预期结果 600 = (10+20)*20
    cout << "#define MyAdd(x, y) ： " << ret << endl; // 实际 410 = 10+20*20
}

//宏定义比较算法
#define defCompare(a, b) ((a) < (b)) ? (a) : (b)

// inline内联
inline void inliCompare(int a, int b) {
    int ret = a < b ? a : b;
    cout << "inline void inliCompare(int a, int b) ：" << ret << endl;
}

// 宏定义缺陷，简单替换
void test02() {
    int a = 10;
    int b = 20;

    int ret = defCompare(++a, b); // 预期结果 11    ((++a) < (b)) ? (++a):(b)
    cout << "#define defCompare(++a, b) ：" << ret << endl; // 实际 12

    a = 10;
    b = 20;
    inliCompare(++a, b); // 11
}

// 内联函数注意事项
// 1.类内实现的成员函数,默认内联,前面会自动加inline关键字
// 2.内联函数声明和实现前都必须加inline
inline void func(); //内联函数声明
inline void func() { //如果函数实现时候，没有加inline关键字，那么这个函数依然不算内联函数
    ;
};

// 宏函数没有作用域

int main() {

    test01();

    test02();

    // system("pause");
    return EXIT_SUCCESS;
}