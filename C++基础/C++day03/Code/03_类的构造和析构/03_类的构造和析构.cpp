#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Person {
  public:
    //构造函数写法
    //与类名相同，没有返回值 ，不写void，可以发生重载 （可以有参数）
    //构造函数由编译器自动调用，而不是手动，而且只会调用一次
    Person() {
        cout << "构造函数调用" << endl;
    }
    // 有参构造
    Person(int a) {
        cout << "构造函数调用(int a)" << endl;
    }
    //拷贝构造函数, const type &
    Person(const Person &p) { // 常引用
        cout << "拷贝构造函数调用" << endl;
    }

    //析构函数写法
    // 与类名相同 类名前面加一个符号 “~” ,也没有返回值 ，不写void， 不可以有参数（不能发生重载）
    //自动调用，只会调用一次
    ~Person() {
        cout << "析构函数调用" << endl;
    }
};

void test01() {
    Person p1; //调用了默认构造和析构，是系统提供的两个空实现的函数
    // Person ppp();   //不调用构造和析构，是函数ppp()声明，返回类型为Person
    Person p2(2); // 调用带形参构造函数
}

// 类声明
class Animal {
  public:
    // 无参构造
    Animal();
    // 有参构造
    Animal(int a);
    //拷贝构造
    Animal(const Animal &ani);

    //析构
    ~Animal();

  private:
};

// 类方法实现
Animal::Animal() {
    cout << "构造函数调用" << endl;
}
Animal::Animal(int a) {
    cout << "构造函数调用(int a)" << endl;
}
//拷贝构造函数, const type &
Animal::Animal(const Animal &ani) { // 常引用
    cout << "拷贝构造函数调用" << endl;
}
Animal::~Animal() {
    cout << "析构函数调用" << endl;
}

void test02() {
    Animal dog; //调用了默认构造和析构，是系统提供的两个空实现的函数

    Animal cat(22); // 调用带形参构造函数
}

int main() {

    test01();

    test02();

    // system("pause");
    return EXIT_SUCCESS;
}