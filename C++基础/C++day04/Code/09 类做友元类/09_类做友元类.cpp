#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

// 前向声明 Building
class Building; // 先声明
class goodGay_friend { // 声明，类外实现
  public:
    goodGay_friend();

    void visit();

  private:
    Building *build;
};

//! 被作为友元的类 必须类外实现,
// 否则error : invalid use of incomplete type ‘class Building’
// note: forward declaration of ‘class Building’
goodGay_friend::goodGay_friend() { // 构造
    build = new Building;
}

// 被作为友元的类 必须类外实现,
// 否则error: invalid use of incomplete type ‘class Building’
// note : forward declaration of ‘class Building’
void goodGay_friend::visit() { // 方法
    cout << "好基友正在访问： " << this->build->m_SittingRoom << endl;
    cout << "好基友正在访问： " << this->build->m_BedRoom << endl; // 可以访问私有属性
}

class Building { // 声明，类外实现
    //让好基友类 作为 Building的好朋友
    friend class goodGay_friend; // friend声明授予权限

  public:
    Building() { // 构造
        this->m_SittingRoom = "客厅";
        this->m_BedRoom = "卧室";
    }

  public:
    string m_SittingRoom; //客厅
  private:
    string m_BedRoom; //卧室
};

void test01() {
    goodGay_friend gg;
    gg.visit();
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}