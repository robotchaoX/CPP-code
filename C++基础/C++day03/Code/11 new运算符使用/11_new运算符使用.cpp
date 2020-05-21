#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void test00() {

    // 单个数据
    int *num = new int;
    int *num1 = new int{-1}; // 赋初值,初始化表,推荐
    int *num2 = new int(-1); // 赋初值
    cout << "*num1 " << *num1 << endl;
    cout << "*num2 " << *num2 << endl;
    delete num;

    // 一维数组的动态分配和释放
    //动态分配空间
    int *arr = new int[10]; // 假定数组长度为10
    // int arr[] = new int[10]; // new返回地址,int arr[]接受值,不可以这样
    int *arr2 = new int[10]{-1, -2, -3, -4}; // 赋初值,初始化表,推荐
    cout << "arr2[1][3][5] " << arr2[1] << arr2[3] << arr2[5] << endl;
    //释放
    delete[] arr;

    // 二维数组的动态分配和释放
    const int M = 10; //行数
    const int N = 20; //列数
    //第三种
    //内存不连续，可以[][],是第一种情况的特例，局限性比较大，比第一种好在能直接delete，方便
    //如果你确实知道N是多少，那么可以用这种，比如说二维数组做形参的时候(此时内存连续)，不是很推荐使用
    int(*arr_2D)[N] = new int[M][N]; // N组指针??
    // arr_2D[M][N] = -1; // [][]使用
    delete[] arr_2D;
    // 缺点：n必须是已知
    // 优点：调用直观，连续储存，程序简洁(经过测试，析构函数能正确调用)

    //第一种
    // 可以直接[][]访问。但是内存不连续，不是很推荐使用，除非M/N都不确定
    int **array2D;
    //假定数组第一维长度为m， 第二维长度为n
    //动态分配空间
    array2D = new int *[M];
    for (int i = 0; i < M; i++) {
        array2D[i] = new int[N];
    }
    //释放
    for (int i = 0; i < M; i++) {
        delete[] array2D[i];
    }
    delete[] array2D;
    // 缺点：非连续储存，程序烦琐，ga为A **类型
    // 优点：调用直观，n可以不是已知

    //第二种，
    // 内存连续，但是不能[][]，最推荐的一种。不能[][]但是你可以通过[i*n+j]来计算  啊
    //这种是1维数组转化为2维数组
    int *arr_1 = new int[M * N];
    // arr[i*n+j]是arr[i][j]
    delete[] arr_1;
    // 缺点：调用不够直观
    // 优点：连续储存，n可以不是已知
}

class Person {
  public:
    Person() {
        cout << "默认构造调用" << endl;
    }

    Person(int a) {
        cout << "有参构造调用" << endl;
    }

    Person(const Person &p) {
        cout << "拷贝构造调用" << endl;
    }

    ~Person() {
        cout << "析构函数调用" << endl;
    }
};

void test01() {
    // 自动栈区开辟
    Person p1; // 无参构造
    Person p2(1); // 有参构造

    // new 堆区开辟
    //所有new出来的对象 都会返回该类型的指针
    Person *p3 = new Person; // 无参构造
    Person *p4 = new Person(2); // 有参构造

    // malloc 返回 void* 还要强转到指定类型
    // malloc会调用构造吗？ 不会  new会调用构造
    // new 运算符  malloc 函数

    // delete 释放堆区空间
    // delete也是运算符 配合 new用  malloc 配合 free用
    delete p3;
    delete p4;
}

void test02() {
    //当用void* 接受new出来的指针 ，会出现无法释放的问题
    void *p = new Person(10); // void *无法释放
    delete p; //无法释放p ，所以避免这种写法
    // ?? delete 无法释放 void *
}

void test03() {
    //通过new开辟数组
    Person *pArray = new Person[3];
    //释放数组 delete []
    delete[] pArray;
    cout << "---" << endl;

    //通过new开辟数组,用初始化表初始化,指定有参构造,只发生一次初始化有参的构造
    Person *pArr = new Person[3]{Person(1), Person(2), Person(3)};
    delete[] pArr;
    cout << "---" << endl;

    //在栈上开辟数组，用初始化表初始化,指定有参构造,只发生一次初始化有参的构造
    Person pArray2[3] = {Person(1), Person(2), Person(3)};
}

int main() {
    // test00();

    // test01();

    // test02();

    test03();

    // system("pause");
    return EXIT_SUCCESS;
}