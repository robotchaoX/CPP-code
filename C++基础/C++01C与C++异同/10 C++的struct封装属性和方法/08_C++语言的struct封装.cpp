#include <cstring>
#include <iostream>

using namespace std;

// C++ struct 封装 属性 和 方法
struct Person {
  public: // struct默认public
    // 属性
    char mName[64];
    int mAge;

    // 方法
    void PersonEat() {
        cout << mName << "吃人饭" << endl;
    }
};

struct Dog {
  public:
    char mName[64];
    int mAge;

    void DogEat() {
        cout << mName << "吃狗粮" << endl;
    }
};

// C++中的struct封装 严格类型转换检测，让属性和行为 绑定到一起
// 1 属性和行为作为一个整体来表示生活中的事物
// 2 控制权限 public 公有权限  protected 保护权限  private 私有权限
void test01() {
    Person p1;
    strcpy(p1.mName, "老王");
    p1.PersonEat();
    // p1.DogEat();
}

// struct 和 class是一个意思，唯一的不同  默认权限 ，
// struct默认权限是public，但是class默认权限是private
class Animal {
    //如果不声明权限，默认的权限是 private
  public:
    int mHeight;

  protected: //保护权限 类内部可以访问 ，(当前类的子类可以访问) , 类外部不可以访问
    int mWeight;

    void setWeight() {
        mWeight = 100;
    };

  private: // class默认private
    // 属性
    int mAge;

    // 方法
    void eat() {
        mAge = 100;
    };
};

//所谓私有权限 就是私有成员(属性、函数) 在类内部可以访问，类外部不可以方法
//公共权限 ，在类内部和类外部都可以访问
void test02() {
    Animal an;
    // an.eat();
    // an.mAge; //私有不可以访问到

    an.mHeight = 100; //公有权限在类外部可以访问到
    // an.mWeight = 100; //保护权限 在类外不可访问到
}

// public  类内 类外 都可以访问
// protected 类内可以访问 类外 不可以访问 （子类可以方法）
// private   类内可以访问 类外 不可以访问  （子类不可以方法）

int main() {
    test01();

    test02();

    return EXIT_SUCCESS;
}