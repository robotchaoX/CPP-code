#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Animal {
  public:
    // virtual 虚函数，发生多态
    virtual void speak() { // 小猫在说话
        // void speak() { // 动物在说话
        cout << "动物在说话" << endl;
    }
};

class Cat : public Animal {
  public:
    void speak() { //
        cout << "小猫在说话" << endl;
    }
};

// 父类的引用或者指针 指向 子类对象

//调用doSpeak ，speak函数的地址早就绑定好了，早绑定，静态联编，编译阶段就确定好了地址
//如果想调用猫的speak，不能提前绑定好函数的地址了，所以需要在运行时候再去确定函数地址
//动态联编，写法 doSpeak方法改为虚函数,在父类上声明虚函数，发生了多态
//如果发生了继承的关系，编译器允许进行类型转换
void doSpeak(Animal &animal) // Animal & animal = cat
{ // 子类重写父类虚函数,子类对象animal调用，就近原则
    animal.speak();
}

void doSpeak2(Cat &cat) // Animal & animal = cat
{ // 子类直接重写父类方法,子类对象cat调用，就近原则
    cat.speak(); // 小猫在说话
}

void test01() {
    Cat cat;
    doSpeak(cat);
    // doSpeak2(cat);
}

// // 内部实现
// void test02() {
//     // cout << sizeof(Animal) << endl;
//     //父类指针指向子类对象 多态
//     Animal *animal = new Cat; // 子类对象

//     // animal->speak();
//     // *(int*)*(int*)animal 函数地址
//     ((void (*)())(*(int *)*(int *)animal))();

//     //  *((int*)*(int*)animal+1)猫吃鱼的地址
//     ((void (*)())(*((int *)*(int *)animal + 1)))();
// }

int main() {

    test01();

    // test02();

    // system("pause");
    return EXIT_SUCCESS;
}