#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//抽象水果
class AbstractFruit {
  public:
    virtual void ShowName() = 0;
};

//苹果
class Apple : public AbstractFruit {
  public:
    virtual void ShowName() {
        cout << "我是苹果!" << endl;
    }
};

//香蕉
class Banana : public AbstractFruit {
  public:
    virtual void ShowName() {
        cout << "我是香蕉!" << endl;
    }
};

//鸭梨
class Pear : public AbstractFruit {
  public:
    virtual void ShowName() {
        cout << "我是鸭梨!" << endl;
    }
};

//水果工厂
class FruitFactory {
  public:
    // 创建具体水果的类方法，返回抽象水果类指针
    static AbstractFruit *CreateFruit(string flag) { // static类方法，通过类名调用
        if (flag == "apple") { // 简单工厂模式不满足开闭原则
            return new Apple;
        } else if (flag == "banana") {
            return new Banana;
        } else if (flag == "pear") {
            return new Pear;
        } else {
            return NULL;
        }
    }
};

void test01() {
    //创建过程需要关心吗？ 直接拿来用

    AbstractFruit *fruit = NULL;
    fruit = FruitFactory::CreateFruit("apple");
    fruit->ShowName();
    delete fruit;

    fruit = FruitFactory::CreateFruit("banana");
    fruit->ShowName();
    delete fruit;

    fruit = FruitFactory::CreateFruit("pear");
    fruit->ShowName();
    delete fruit;
}

int main(void) {
    test01();
    return 0;
}