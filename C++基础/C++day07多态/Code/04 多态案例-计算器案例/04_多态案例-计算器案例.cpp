#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// 没有多态实现计算器
class Calculator {
  public:
    void setv1(int v) {
        this->val1 = v;
    }

    void setv2(int v) {
        this->val2 = v;
    }

    // 不符开闭原则
    int getResult(string oper) {
        if (oper == "+") {
            return val1 + val2;
        } else if (oper == "-") {
            return val1 - val2;
        } else {
            return -1;
        }
    }

  private:
    int val1;
    int val2;
};

void test01() {
    Calculator cal;
    cal.setv1(30);
    cal.setv2(10);
    cout << cal.getResult("+") << endl;
    cout << cal.getResult("-") << endl;
}

// 开闭原则: 对扩展开放,对修改关闭

//利用多态实现计算器
class AbstractCalculator {
  public:
    // 普通析构 是不会调用子类的析构的，所以可能会导致释放不干净
    // 虚析构函数
    // 否则  warning: deleting object of abstract class type ‘abstractCalculator’ which has non-virtual destructor will
    // cause undefined behavior [-Wdelete-non-virtual-dtor]
    virtual ~AbstractCalculator() {
    }

    //虚函数(非纯虚函数)
    // virtual int getResult(){ return 0; };

    //纯虚函数
    //如果父类中有了 纯虚函数  子类继承父类，就必须要实现 纯虚函数
    //如果父类中 有了 纯虚函数 ，这个父类 就无法实例化对象了
    //这个类有了纯虚函数，通常又称为 抽象类
    virtual int getResult() = 0; //纯虚函数

    void setv1(int v) {
        this->val1 = v;
    }

    void setv2(int v) {
        this->val2 = v;
    }

  public:
    int val1;
    int val2;
};

//如果父类中有了 纯虚函数  子类继承父类，就必须要实现 纯虚函数
class EmptyCalculator : public AbstractCalculator {
  public:
    virtual int getResult() {
        return 0;
    }
};

//加法计算器
class PlusCalculator : public AbstractCalculator {
  public:
    virtual int getResult() {
        return val1 + val2;
    };
};
//减法计算器
class SubCalculator : public AbstractCalculator {
  public:
    virtual int getResult() {
        return val1 - val2;
    };
};
//乘法计算器
class ChengCalculator : public AbstractCalculator {
  public:
    virtual int getResult() {
        return val1 * val2;
    };
};

void test02() {
    // 父类指针
    AbstractCalculator *abs_cal;

    // 父类指针 = 子类对象指针
    abs_cal = new PlusCalculator; // 加法计算器
    abs_cal->setv1(10);
    abs_cal->setv2(20);
    // 调用多态
    cout << abs_cal->getResult() << endl;
    delete abs_cal; // 析构多态

    // 父类指针 = 子类对象指针
    abs_cal = new SubCalculator;
    abs_cal->setv1(10);
    abs_cal->setv2(20);
    cout << abs_cal->getResult() << endl;
    delete abs_cal;

    // 父类指针 = 子类对象指针
    abs_cal = new ChengCalculator; // 子类对象指针
    abs_cal->setv1(10);
    abs_cal->setv2(20);
    cout << abs_cal->getResult() << endl;
    delete abs_cal;

    //如果父类有了纯虚函数，不能实例化对象了
    // AbstractCalculator aaa; // error
    // AbstractCalculator *abc = new AbstractCalculator; // error
}

int main() {

    test01();

    test02();

    // system("pause");
    return EXIT_SUCCESS;
}