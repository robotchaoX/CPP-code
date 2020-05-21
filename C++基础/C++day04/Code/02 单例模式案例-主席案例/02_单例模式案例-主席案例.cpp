#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//创建主席类
//需求 单例模式  为了创建类中的对象，并且保证只有一个对象实例
class ChairMan {
  private:
    // 3.构造函数 私有化,使无法自动构造
    ChairMan() {
        cout << "...构造函数" << endl;
    }
    // 拷贝构造函数 私有化,使无法拷贝构造
    ChairMan(const ChairMan &c) {
        cout << "...拷贝构造" << endl;
    }

  public:
    // 2.提供对外接口  访问主席指针
    static ChairMan *getInstance() { // 属于类
        return singleMan; // 返回static类指针
    }

  private:
    // 1.静态类指针属性 私有化
    static ChairMan *singleMan; // 当前类指针,属于类
};
// static 类内定义 类外实现
ChairMan *ChairMan::singleMan = new ChairMan; // 无论有没有使用ChairMan,初始化都会调用构造函数,主席创建在main之前

void test01() {

    // // 不可以创建对象,不能调用构造函数
    // ChairMan c1;
    // // 不可以拷贝构造
    // ChairMan c2(c1);
    // // 不可以new对象
    // ChairMan *c3 = new ChairMan;
    // ChairMan *c4 = new ChairMan(*c1); // 不可以拷贝构造??
    // // singleMan私有无法访问
    // ChairMan *cm = ChairMan::singleMan;
    // ChairMan::singleMan = NULL;

    // 创建类对象指针,只有一个对象
    ChairMan *cm1 = ChairMan::getInstance();
    ChairMan *cm2 = ChairMan::getInstance();
    if (cm1 == cm2) {
        cout << "cm1 与 cm2相同" << endl;
    } else {
        cout << "cm1 与 cm2不相同" << endl;
    }
}

int main() {

    cout << "--- main调用" << endl; // 主席创建先于main调用
    test01();

    // system("pause");
    return EXIT_SUCCESS;
}