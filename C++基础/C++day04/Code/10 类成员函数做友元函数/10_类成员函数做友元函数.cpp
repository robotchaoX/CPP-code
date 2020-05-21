#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

//只让 visit可以作Building的好朋友  visit_common 不可以访问私有属性
// 前向声明 Building
class Building; // 先声明
class GoodGay { // 声明，类外实现
  public:
    GoodGay();

    // 成员函数做友元,可以访问Building私有属性
    void visit_friend();
    // 普通成员函数
    void visit_common();

  private:
    Building *build;
};

class Building { // 声明，类外实现
    //让成员函数 visit_friend 作为友元函数,可以访问Building私有属性
    friend void GoodGay::visit_friend(); // 声明授予权限

  public:
    Building() {
        this->m_SittingRoom = "客厅";
        this->m_BedRoom = "卧室";
    }

  public:
    string m_SittingRoom; //客厅
  private:
    string m_BedRoom; //卧室
};

//! 被作为友元的类 必须类外实现,
// 否则error : invalid use of incomplete type ‘class Building’
// note: forward declaration of ‘class Building’
GoodGay::GoodGay() { // 构造
    build = new Building;
}
// 成员函数做友元,可以访问Building私有属性
void GoodGay::visit_friend() { // 方法
    cout << "好基友正在访问： " << this->build->m_SittingRoom << endl;
    cout << "好基友正在访问： " << this->build->m_BedRoom << endl; // 可以访问私有属性
}
// 普通成员函数
void GoodGay::visit_common() { // 方法
    cout << "好基友正在访问： " << this->build->m_SittingRoom << endl;
    // cout << "好基友正在访问： " << this->build->m_BedRoom << endl; // error
}

void test01() {
    GoodGay gg;
    // 成员函数做友元,可以访问Building私有属性
    gg.visit_friend();

    // 普通成员函数
    gg.visit_common();
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}