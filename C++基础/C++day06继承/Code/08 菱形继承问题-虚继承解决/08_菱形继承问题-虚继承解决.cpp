#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// 共同基类
class Animal {
  public:
    int m_Age;
};

//虚基类 Sheep, 虚继承 共同基类
class Sheep : virtual public Animal {
  public:
    ;
};
//虚基类 Tuo, 虚继承 共同基类
class Tuo : virtual public Animal {
  public:
    ;
};

// 菱形继承
class SheepTuo : public Sheep, public Tuo {
  public:
    ;
};

// 菱形继承的解决方案 利用虚继承
// 操作的是共享的一份数据
void test01() {
    SheepTuo st;
    st.Sheep::m_Age = 10;
    st.Tuo::m_Age = 20; // 虚继承共享重名属性数据

    cout << st.Sheep::m_Age << endl;
    cout << st.Tuo::m_Age << endl;
    cout << st.SheepTuo::m_Age << endl;
    cout << st.m_Age << endl; // 可以直接访问，原因已经没有二义性的可能了，只有一份m_Age
}

//  内部工作原理 通过地址 找到 偏移量

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}