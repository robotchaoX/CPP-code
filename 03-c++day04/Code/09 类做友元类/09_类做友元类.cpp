#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Building; // 先声明
class goodGay { // 声明，类外实现
  public:
    goodGay();

    void visit();

  private:
    Building *building;
};

class Building { // 声明，类外实现
    //让好基友类 作为 Building的好朋友
    friend class goodGay;

  public:
    Building();

  public:
    string m_SittingRoom; //客厅
  private:
    string m_BedRoom; //卧室
};

// 类外实现,否则note: forward declaration of ‘class Building’
goodGay::goodGay() { building = new Building; }
void goodGay::visit() {
    cout << "好基友正在访问： " << this->building->m_SittingRoom << endl;
    cout << "好基友正在访问： " << this->building->m_BedRoom << endl;
}

// 类外实现
Building::Building() {
    this->m_SittingRoom = "客厅";
    this->m_BedRoom = "卧室";
}

void test01() {
    goodGay gg;
    gg.visit();
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}