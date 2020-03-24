#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//抽象策略类
class AbstractStrategy {
  public:
    virtual int CaculateMoney(int) = 0;
};

// 8折策略
class StrategySaleByEight : public AbstractStrategy {
  public:
    virtual int CaculateMoney(int money) {
        return money * 0.8;
    }
};

//满200 返现100策略
class StrategySale200Return100 : public AbstractStrategy {
  public:
    virtual int CaculateMoney(int money) {
        return money - (money / 200) * 100;
    }
};

//超市购物类
class Shopping {
  public:
    Shopping() {
        pStrategy = NULL;
    }
    void setStrategy(AbstractStrategy *strategy) {
        pStrategy = strategy;
    }
    void PayMoney(int money) {
        int realMoney = 0;
        if (NULL == pStrategy) {
            realMoney = money;
        } else {
            realMoney = pStrategy->CaculateMoney(money);
        }
        cout << "商品折前价格:" << money << ",折后价格:" << realMoney << "元!" << endl;
    }

  private:
    AbstractStrategy *pStrategy;
};

void test01() {

    Shopping *shopping = new Shopping;
    AbstractStrategy *strategy = NULL;
    cout << "逢活动 八折优惠" << endl;
    strategy = new StrategySaleByEight;
    shopping->setStrategy(strategy); //设置商场活动为8折优惠
    shopping->PayMoney(600);

    delete strategy;

    cout << "再次逢活动 满200 返现100" << endl;
    strategy = new StrategySale200Return100;
    shopping->setStrategy(strategy);
    shopping->PayMoney(900);

    delete strategy;
    delete shopping;
}

// 商场促销有策略 A（0.8 折） 策略 B（消费满 200，返现 100），用策略模式模拟场景。
int main() {

    test01();

    return EXIT_SUCCESS;
}