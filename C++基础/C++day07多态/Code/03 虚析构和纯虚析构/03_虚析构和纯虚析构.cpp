#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Animal {
  public:
    Animal() {
        cout << "Animal的构造调用" << endl;
    }

    // 普通析构 是不会调用子类的析构的，所以可能会导致释放不干净
    // 非虚析构函数,可能释放不干净
    ~Animal() {
        cout << "Animal的析构调用" << endl;
    }

    // 虚析构函数
    // virtual ~Animal() {
    //     cout << "Animal的析构调用" << endl;
    // }
};

class Cat : public Animal {
  public:
    Cat() {
        dd = new double[1000000000];
        cout << "Cat的默认构造调用" << endl;
    }

    Cat(const char *name) {
        dd = new double[1000000000];
        cout << "Cat的有参构造调用" << endl;
        this->m_Name = new char[strlen(name) + 1];
        strcpy(this->m_Name, name);
    }

    ~Cat() {
        delete[] dd;
        cout << "Cat的析构调用" << endl;
        if (this->m_Name != NULL) {
            delete[] this->m_Name;
            this->m_Name = NULL;
        }
    }

  public:
    char *m_Name;
    double *dd;
};

void test01() {

    cout << "++++++++++++++++" << endl;
    // 创建子类对象时,先构造父类,再构造子类
    // 父类指针指向子类对象
    Animal *animal = new Cat("TOM");
    cout << "---------" << endl;
    delete animal; // 多态释放??
    // 当virtual虚析构函数时,父类Cat子类Animal能正常释放
    // 当非虚析构函数时,只释放父类Animal,派生类Cat不会释放,导致内存泄露
    cout << "---------" << endl;

    cout << "++++++++++++++++" << endl;
    // 创建子类对象时,先构造父类,再构造子类
    // 指针类型一致,没有多态
    Cat *cat = new Cat("TOM"); // 不论都能正常析构
    cout << "---------" << endl;
    // 析构子类对象时,与构造顺序相反,先析构子类,再析构父类
    delete cat;
    cout << "---------" << endl;
    cout << "++++++++++++++++" << endl;
}

// 测试内存溢出
// virtual 虚析构函数能正常运行,非虚析构函数内存溢出中途报错
void test02() {
    for (int i = 0; i < 100000; i++) {
        test01();
    }
    cout << "............" << endl;
    usleep(1000000);
}

class Animal2 {
  public:
    Animal2() {
        cout << "Animal的构造调用" << endl;
    }

    virtual void speak() { // 父类虚函数
        cout << "动物在说话" << endl;
    }

    //纯虚析构 写法如下
    //纯虚析构 ，需要声明 还需要实现 类内声明，类外实现
    virtual ~Animal2() = 0; // =0只是形式上的
    //如果函数中出现了 纯虚析构函数，那么这个类也算抽象类
    //抽象类 不可实例化对象
};
//纯虚析构函数实现
Animal2::~Animal2() {
    cout << "Animal2的纯虚析构调用" << endl;
}

// 如果出现纯虚析构，类也算抽象类，不能实例化对象
void func() {
    // Animal2 an; // error
    // Animal2 *animal = new Animal2; // error
}

class Cat2 : public Animal2 {
  public:
    Cat2() {
        cout << "Cat的构造调用" << endl;
    }
    Cat2(const char *name) {
        cout << "Cat的有参构造调用" << endl;
        this->m_Name = new char[strlen(name) + 1];
        strcpy(this->m_Name, name);
    }

    virtual void speak() {
        cout << "小猫在说话" << endl;
    }

    ~Cat2() {
        cout << "Cat的析构调用" << endl;
        if (this->m_Name != NULL) {
            delete[] this->m_Name;
            this->m_Name = NULL;
        }
    }

  public:
    char *m_Name;
};

void test03() {
    // 父类对象指针或引用指向子类对象
    Animal2 *animal2 = new Cat2("TOM");
    animal2->speak(); // 调用多态
    delete animal2; // 释放多态

    cout << "++++++++++++++++" << endl;

    // 指针类型一致,没有多态
    Cat2 *cat2 = new Cat2("TOM");
    cat2->speak();
    delete cat2;
}
int main() {

    // test01();

    // test02();

    test03();

    // system("pause");
    return EXIT_SUCCESS;
}