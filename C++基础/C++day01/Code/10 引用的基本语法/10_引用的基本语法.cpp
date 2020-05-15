#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// 1、引用基本语法  type &别名 = 原名
void test01() {
    int a = 1;
    int &b = a; // 引用

    b = 2;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

// 2、引用必须初始化
void test02() {
    int a = 10;
    // int &b; // 必须初始化 error
    int &b = a; //引用初始化后不可以修改了

    int c = 30;
    b = c; //赋值！！！
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
}

// 3、对数组建立引用
void test03() {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    //给数组起别名  type (&数组引用)[数组大小] = 数组名;
    int(&p_Arr)[10] = arr; // 数组的引用
    for (int i = 0; i < 10; i++) {
        cout << p_Arr[i] << " ";
    }
    cout << endl;

    //第二种方式 typedef起别名
    typedef int(ARRAYREF)[10]; //一个具有10个元素的int类型的数组
    ARRAYREF &pArr2 = arr;

    for (int i = 0; i < 10; i++) {
        cout << pArr2[i] << " ";
    }
    cout << endl;
}

//引用的注意事项
// 1、 引用必须引一块合法的内存空间
// int &a = 10; // 不合法，引用必须引一块合法的内存空间
// 2、不要返回局部变量的引用

// 返回局部变量的引用&
int &temref() {
    int localVar = 10; // 局部变量，报错
    cout << "localVar = " << localVar << endl;
    //  warning: reference to local variable ‘aa’ returned [-Wreturn-local-addr]
    return localVar; // 返回局部变量aa的引用,运行时报错
}

// 函数的返回值是引用&
int &doWork2() {
    // int a = 10; // 局部变量，报错
    static int a = 10; // static 全局生存周期
    cout << "a = " << a << endl;

    return a; // 函数返回值是引用
}
void test04() {

    int &ret = doWork2(); //相当于写了 int &ret = a ;
    cout << "ret = " << ret << endl;

    //如果函数的返回值是引用，那么这个函数调用可以作为左值
    doWork2() = 1000; //相当于写了 a = 1000;

    cout << "---" << endl;
    cout << "doWork2():" << doWork2() << endl;
    cout << "---" << endl;
}

int main() {

    test01();

    test02();

    test03();

    test04();

    // system("pause");
    return EXIT_SUCCESS;
}