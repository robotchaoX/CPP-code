#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Building {
    // 让全局的好基友函数 变为我的好朋友  友元函数,可以访问所有私有属性
    friend void goodGay_friend(Building *building); // friend声明授予权限

  public:
    Building() {
        this->m_SittingRoom = "客厅";
        this->m_BedRoom_private = "卧室";
    }

  public:
    string m_SittingRoom; //客厅

  private:
    string m_BedRoom_private; //卧室
};

// 全局函数 好基友
void goodGay_friend(Building *building) { // 类作为形参
    cout << "好基友正在访问 " << building->m_SittingRoom << endl;
    cout << "好基友正在访问 " << building->m_BedRoom_private << endl;
}

// 友元函数 目的访问类中的私有成员属性
void test01() {
    Building *building = new Building;
    // 类友元函数
    goodGay_friend(building);
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}