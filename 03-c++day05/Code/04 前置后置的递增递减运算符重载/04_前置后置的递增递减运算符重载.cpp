#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyInteger {
    friend ostream &operator<<(ostream &cout, MyInteger &myInt);

  public:
    MyInteger() { m_Num = 0; };

    //前置++重载
    MyInteger &operator++() {
        this->m_Num++;
        return *this;
    }

    //后置++ 重载
    MyInteger operator++(int) {
        //先保存目前数据
        MyInteger tmp = *this;
        this->m_Num++;
        // cout << tmp << endl;
        return tmp;
    }
    int m_Num;
};

// 只能利用全局函数 进行 << 运算符的重载
ostream &operator<<(ostream &cout, MyInteger &myInt) {
    cout << myInt.m_Num;
    return cout;
}

void test01() {
    MyInteger myInt;

    cout << "myInt " << myInt << endl;
    cout << "++myInt " << ++myInt << endl; // 前置++
    cout << "myInt " << myInt << endl;
    cout << "myInt++.m_Num " << myInt++.m_Num << endl; // 后置++
    // cout << "myInt++ " << (MyInteger &)myInt++ << endl; // 后置++ 无法直接重载<<输出
    cout << "myInt " << myInt << endl;

    cout << "++(++myInt) " << ++(++myInt) << endl;
    cout << "myInt " << myInt << endl;
}

int main() {

    test01();

    /*int a = 10;
    cout << ++(++a) << endl;
    cout << a << endl;*/

    // system("pause");
    return EXIT_SUCCESS;
}