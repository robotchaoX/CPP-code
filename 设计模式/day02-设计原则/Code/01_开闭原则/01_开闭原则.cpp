#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 开闭原则
// 对扩展开放，对修改关闭，增加功能是通过增加代码来实现，而不是去修改源代码

//计算器的抽象类
class AbstractCalculator {
  public:
    virtual int getResult() = 0;
    virtual void setOperatorNumber(int a, int b) = 0;
    virtual ~AbstractCalculator(){}; // 虚析构
};

//加法计算器类
class PlusCalculator : public AbstractCalculator {
  public:
    virtual void setOperatorNumber(int a, int b) {
        this->mA = a;
        this->mB = b;
    }
    virtual int getResult() {
        return mA + mB;
    }

  public:
    int mA;
    int mB;
};

//减法计算器
class MinuteCalculator : public AbstractCalculator {
  public:
    virtual void setOperatorNumber(int a, int b) {
        this->mA = a;
        this->mB = b;
    }
    virtual int getResult() {
        return mA - mB;
    }

  public:
    int mA;
    int mB;
};

//乘法计算器
class MultiplyCalculator : public AbstractCalculator {
  public:
    virtual void setOperatorNumber(int a, int b) {
        this->mA = a;
        this->mB = b;
    }
    virtual int getResult() {
        return mA * mB;
    }

  public:
    int mA;
    int mB;
};

//取模计算器  通过增加代码来实现
class ModCalculator : public AbstractCalculator {
  public:
    virtual void setOperatorNumber(int a, int b) {
        this->mA = a;
        this->mB = b;
    }
    virtual int getResult() {
        return mA % mB;
    }

  public:
    int mA;
    int mB;
};

void test01() {

    AbstractCalculator *calculator = new PlusCalculator;
    calculator->setOperatorNumber(10, 20);
    cout << "ret:" << calculator->getResult() << endl;

    delete calculator;

    calculator = new MinuteCalculator;
    calculator->setOperatorNumber(10, 20);
    cout << "ret:" << calculator->getResult() << endl;
}

int main(void) {
    test01();
    return 0;
}