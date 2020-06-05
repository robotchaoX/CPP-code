#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// virtual虚函数 实现多态
class Animal {
  public:
    // 声明virtual 虚函数，发生多态
    virtual void speak_virtual() { // 小猫在说话
        cout << "动物在说话" << endl;
    }

    // 非虚函数,不会发生多态
    void speak_normal() { // 动物在说话
        cout << "动物在说话" << endl;
    }

    // 普通非虚析构 是不会调用子类的析构的，所以可能会导致释放不干净
    // 虚析构函数
    virtual ~Animal() {
        cout << "Animal的析构调用" << endl;
    }
};

class Cat : public Animal {
  public:
    // 基类虚函数会传递,其派生类自动变为虚函数,派生类virtual加不加都可以
    // virtual void speak_virtual(){// 虚函数
    void speak_virtual() { // 虚函数
        cout << "小猫在说话" << endl;
    }

    // 非虚函数,不会发生多态
    void speak_normal() { // 非虚函数
        cout << "小猫在说话" << endl;
    }

    ~Cat() {
        cout << "Cat的析构调用" << endl;
    }
};

// 多态:父类的引用或者指针 指向 子类对象

void test01() {
    Cat cat1; // 子类对象
    // 父类的指针 指向 子类对象
    Animal *ani_ptr = &cat1; // 基类指针 指向 派生类
    // 父类的指针 指向 子类对象
    // Animal *ani_ptr = new Cat; // 基类指针 指向 派生类

    ani_ptr->speak_normal(); // 非虚函数,没有多态
    cout << "----" << endl;
    ani_ptr->speak_virtual(); // 虚函数,发生多态

    cout << "---------" << endl;

    Cat cat2; // 子类对象
    // 父类的引用 指向 子类对象
    Animal &ani_ref = cat2;

    ani_ref.speak_normal(); // 非虚函数,没有多态
    cout << "----" << endl;
    ani_ref.speak_virtual(); // 虚函数,发生多态
}

// 函数形参传引用,父类的引用 指向 子类对象
// 实参为子类对象时,满足父类引用指向子类对象,虚函数发生多态
void doSpeak_Ani(Animal &animal) { // Animal & animal = cat
    // 子类重写了父类方法,子类对象animal调用，就近原则
    // 非虚函数,不会发生多态
    // 当实参为父类对象时,就是父类自己的方法
    // 当实参为子类对象时,隐式类型转换Cat->Animal
    animal.speak_normal(); // 动物在说话
    // 虚函数,传入父类引用或指针发生多态
    // 当实参为父类对象时,就是父类自己的方法,虚函数不发生多态
    //! 当实参为子类对象时,满足父类引用指向子类对象,虚函数发生多态
    animal.speak_virtual(); // 可能发生多态,动物在说话/小猫在说话
}

void doSpeak_Cat(Cat &cat) { // Animal & animal = cat
    // 子类直接重写了父类方法,子类对象cat调用，就近原则
    cat.speak_normal(); // 小猫在说话
    cat.speak_virtual(); // 小猫在说话
}

// 非虚函数,没有多态
void test02() {
    Animal ani; // 父类对象
    doSpeak_Ani(ani); // 动物在说话
    // doSpeak_Cat(ani); // error 不可向下类型转换,不可赋值
    cout << "---------" << endl;

    Cat cat; // 子类对象
    // 虚函数,发生多态
    // 非虚函数,没有多态,隐式类型转换Cat->Animal
    doSpeak_Ani(cat); // 虚函数,发生多态;非虚函数,没有发生多态
    doSpeak_Cat(cat); // 小猫在说话
}

//调用doSpeak，speak函数的地址早就绑定好了，早绑定，静态联编，编译阶段就确定好了地址
//如果想调用猫的speak，不能提前绑定好函数的地址了，所以需要在运行时候再去确定函数地址
//动态联编，写法 doSpeak方法改为虚函数,在父类上声明虚函数，发生了多态
//如果发生了继承的关系，编译器允许进行类型转换

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

    // test01();

    // test02();

    // test03();

    // system("pause");
    return EXIT_SUCCESS;
}