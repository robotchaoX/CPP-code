#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//交换int类型两个数字
void mySwapInt(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

//交换double数据
void mySwapDouble(double &a, double &b) {
    double tmp = a;
    a = b;
    b = tmp;
}

//类型，逻辑又非常相似
//类型参数化  泛型编程 -- 模板技术
template <class T> // 告诉编译器 下面如果出现T不要报错，T是一个通用的类型
void mySwap_T(T &a, T &b) { // 传引用
    T tmp = a;
    a = b;
    b = tmp;
}

template <class T>
void mySwap2() { //
}

// template<typename T>  等价于 template<class T>
template <typename T> //
T myAdd_T(T a, T b) { // 传值
    return a + b;
}

void test01() {
    int a = 10;
    int b = 20;
    char c1 = 'c';
    
    // 1 自动类型推导,必须有参数类型才可以推导
    mySwap_T(a, b); // 类型一致,自动推导类型
    // 类型推导不会进行隐式类型转换
    // mySwap_T(a, c1); // error 类型不一致,不会进行隐式类型转换,推导不出来T
    // mySwap_T<int>(a, c1); // error 类型不一致,推导不出来T,显式指定也不能类型转换,传引用
    // myAdd_T(a, c1); // error 类型不一致,不会进行隐式类型转换,推导不出来T
    myAdd_T<int>(a, c1); //?? 传值可以

    // 2 显式指定<类型>
    mySwap_T<int>(a, b); // 指定<类型>

    // 无参模板必须要指定出T才可以使用
    mySwap2<double>(); // 无参
    // mySwap2();// 无参，无法推导，必须显式指定类型

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    double c = 3.14;
    double d = 1.1;
    int e = 5;
    // 类型一致,自动推导类型
    mySwap_T(c, d); // 自动类型推导
    // mySwap_T(c, e); // error 类型不一致,推导不出来T，所以不能运行
    // mySwap_T<double>(c, e); // error 类型不一致,推导不出来T,显式指定也不能类型转换
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}