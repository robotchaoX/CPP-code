#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

// virtual虚函数 实现多态
class AbsAnimal {
  public:
    // 声明virtual 虚函数，发生多态
    // 纯虚函数 virtual =0
    // 纯虚函数,必须在子类中实现,不然仍是抽象类
    virtual void speak_pure_virtual() = 0; // =0只是形式上的
    // 如果类中出现了 纯虚函数，那么这个类是抽象类
    // 抽象类 不可实例化对象

    // 普通非虚析构 是不会调用子类的析构的，所以可能会导致释放不干净
    // 虚析构函数
    virtual ~AbsAnimal() {
        cout << "AbsAnimal的析构调用" << endl;
    }
};
// 即使立即类外实现了纯虚函数,这个类仍然是抽象类,不可实例化对象
// void AbsAnimal::speak_pure_virtual() { // 多余
//     cout << "AbsAnimal的纯虚析构调用" << endl;
// }

// 如果出现纯虚析构，类也算抽象类，不能实例化对象
void test01() {
    // 抽象类，不能实例化对象
    // AbsAnimal ani; // error
    // AbsAnimal *animal = new AbsAnimal; // error
}

class Cat : public AbsAnimal {
  public:
    // 基类虚函数会传递,其派生类自动变为虚函数,派生类virtual加不加都可以
    // 如果父类中有了 纯虚函数,子类继承父类，就必须要实现 纯虚函数
    // 实现基类纯虚函数
    virtual void speak_pure_virtual() { // 虚函数
        cout << "小猫在说话" << endl;
    }

    ~Cat() {
        cout << "Cat的析构调用" << endl;
    }
};

void test02() {
    // 父类对象指针或引用指向子类对象
    AbsAnimal *absAnimal = new Cat;
    absAnimal->speak_pure_virtual(); // 调用多态
    delete absAnimal; // 释放多态

    cout << "++++++++++++++++" << endl;

    // 指针类型一致,没有多态
    Cat *cat = new Cat;
    cat->speak_pure_virtual();
    delete cat;
}
int main() {
    // test01();

    test02();

    // system("pause");
    return EXIT_SUCCESS;
}