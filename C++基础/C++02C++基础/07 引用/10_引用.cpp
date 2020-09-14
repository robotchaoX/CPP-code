#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// 1、引用基本语法  type &别名 = 原名
void test01() {
    int val = 1;
    int &ref = val; // 引用

    ref = 2; // 修改值

    cout << "val = " << val << endl;
    cout << "ref = " << ref << endl;
}

// 2、引用必须初始化
void test02() {
    int a = 10;
    // int &b; // error 引用必须初始化
    int &b = a; //引用初始化后不可以修改了

    int c = 30;
    b = c; //赋值！！！
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
}

// 3、对数组建立引用
void test03() {
    int arr[3] = {1, 2, 3};
    // 数组的引用，就是数组的别名
    // 类型 (&数组引用)[数组大小] = 数组名;
    int(&arr_ref)[3] = arr;

    for (int i = 0; i < 3; i++) {
        cout << arr_ref[i] << " ";
    }
    cout << endl;

    int arr2[3] = {1, 2, 3};
    //第二种方式 typedef给数组起别名
    typedef int(ARRAYREF)[3]; //一个具有10个元素的int类型的数组
    ARRAYREF &pArr2 = arr2;
}

// 形参为数组的引用
void arrRef(int (&array)[5]) {
    cout << "size:" << sizeof(array) << endl;
    for (int i = 0; i < sizeof(array) / 4; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int test033() {
    int array[5] = {1, 2, 3, 4, 5};
    // 实参数组
    arrRef(array);
}

//引用的注意事项
// 1、 引用必须引一块合法的内存空间
//     int &a = 10; // 不合法，引用必须引一块合法的内存空间
// 2、不要返回局部变量的引用

// 不要返回局部变量的引用&
int &temref() {
    int localVar = 10; // 局部变量，报错
    cout << "localVar = " << localVar << endl;
    //  warning: reference to local variable ‘aa’ returned [-Wreturn-local-addr]
    return localVar; // 返回局部变量的引用,运行时报错
}

// 函数的返回值是 引用&
int &doWork2() {
    // int a = 10; // 局部变量，报错
    static int a = 10; // static 全局生存周期
    cout << "a = " << a << endl;

    return a; // return时取引用
}
void test04() {

    int &ret = doWork2(); //相当于写了 int &ret = a ;
    cout << "ret = " << ret << endl;

    //如果函数的返回值是引用，那么这个函数调用可以作为左值
    doWork2() = 1000; //相当于写了 a = 1000;

    cout << "---" << endl;
    cout << "doWork2():" << doWork2() << endl; // 1000
    cout << "---" << endl;
}

class Person {
    // 友元访问私有属性
    friend ostream &operator<<(ostream &cout, Person &p1);

  public:
    Person() {
        cout << "默认构造函数调用" << endl;
    }
    Person(int a) {
        m_Age = a;
        cout << "有参构造函数调用" << endl;
    }
    Person(const Person &p) { // 拷贝构造函数
        m_Age = p.m_Age;
        cout << "拷贝构造函数调用" << endl;
    }

    ~Person() {
        cout << "析构函数调用" << endl;
    }

  public:
    int m_Age = -1;
};
// 只能利用全局函数 进行 << 运算符的重载
// 返回类型 ostream & , 第一个参数 cout , 第二个参数 p1
ostream &operator<<(ostream &cout, Person &p1) { // 全局 operator<<(cout,p1)
    // 插入到输出流cout
    cout << "m_Age = " << p1.m_Age;

    return cout; // 返回输出流cout的引用
}

// 返回对象的引用 Person &
Person &objref() {
    // static 全局生存周期
    static Person per = Person(0); // 有参构造

    return per; // 返回变量的引用
}
void test05() {

    Person &ref = objref(); //相当于写了 Person &ref = Person(0);
    cout << "ref: " << ref << endl;

    cout << "..." << endl;
    Person p2 = Person(22); // 有参构造
    //如果函数的返回值是引用，那么这个函数调用可以作为左值
    objref() = p2; // 已存在的对象相互赋值不会发生拷贝构造
    cout << "..." << endl;

    cout << "---" << endl;
    cout << "objref():" << objref() << endl;
    cout << "---" << endl;
}

int main() {

    test01();

    test02();

    test03();

    test04();

    test05();

    // system("pause");
    return EXIT_SUCCESS;
}