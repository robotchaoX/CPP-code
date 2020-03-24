#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//商品类
class Goods {
  public:
    Goods(bool IsReal, string GoodsName) : m_IsReal(IsReal), m_GoodsName(GoodsName) {
    }
    bool getIsReal() {
        return m_IsReal;
    }
    string getGoodsName() {
        return m_GoodsName;
    }

  private:
    bool m_IsReal; //商品真假
    string m_GoodsName; //商品名称
};

//购物抽象
class AbstractShopping {
  public:
    virtual void BuyGoods(Goods *) = 0;
};

//韩国购物
class KoreaShopping : public AbstractShopping {
  public:
    virtual void BuyGoods(Goods *goods) {
        cout << "在韩国购买" << goods->getGoodsName() << endl;
    }
};

//美国购物
class AmericanShopping : public AbstractShopping {
  public:
    virtual void BuyGoods(Goods *goods) {
        cout << "在美国购买" << goods->getGoodsName() << endl;
    }
};

//非洲购物
class AfricanShopping : public AbstractShopping {
  public:
    virtual void BuyGoods(Goods *goods) {
        cout << "在非洲购买" << goods->getGoodsName() << endl;
    }
};

//自己购物
void test01() {
    AbstractShopping *shopping = NULL;

    //去美国买啤酒
    Goods *bear = new Goods(true, "啤酒");
    shopping = new AmericanShopping;
    shopping->BuyGoods(bear);
    delete bear;
    delete shopping;

    //去韩国买化妆品
    Goods *cosmetics = new Goods(true, "化妆品");
    shopping = new KoreaShopping;
    shopping->BuyGoods(cosmetics);
    delete cosmetics;
    delete shopping;

    Goods *ivory = new Goods(true, "象牙");
    shopping = new AfricanShopping;
    shopping->BuyGoods(ivory);
    delete ivory;
    delete shopping;
}

//现在我不想自己去购物了  自己需要花费路费 还有自己办理货品海关检查 自己辨别商品真伪
//海外代购 帮助检查商品真伪 海关检查
class OverseasShopping : public AbstractShopping {
  public:
    OverseasShopping(AbstractShopping *mode) {
        pShoppingMode = mode; //购物模式  去韩国买  还是去美国买 还是去非洲买
    }
    virtual void BuyGoods(Goods *goods) {
        if (GoodsIsReal(goods)) { //如果产品是真的
            CheckGoods(); //海关检查
            pShoppingMode->BuyGoods(goods);
        } else {
            cout << goods->getGoodsName() << "是假商品，放弃购买!" << endl;
        }

        delete goods;
    }
    //辨别商品真伪
    bool GoodsIsReal(Goods *goods) {
        cout << "海外代理检查 " << goods->getGoodsName() << "货品真伪" << endl;
        return goods->getIsReal();
    }
    void CheckGoods() {
        cout << "海外代理商品海关检查" << endl;
    }
    ~OverseasShopping() {
        if (NULL != pShoppingMode) {
            delete pShoppingMode;
        }
    }

  private:
    AbstractShopping *pShoppingMode;
};

void test02() {

    AbstractShopping *proxy = NULL;
    //创建一个去韩国购物的代理
    proxy = new OverseasShopping(new KoreaShopping);
    proxy->BuyGoods(new Goods(true, "化妆品"));
    delete proxy;

    cout << "-----------------------" << endl;

    //创建一个去美国买啤酒的代理
    proxy = new OverseasShopping(new AmericanShopping);
    proxy->BuyGoods(new Goods(false, "啤酒"));
    delete proxy;

    cout << "-----------------------" << endl;

    //创建一个去非洲买啤象牙的代理
    proxy = new OverseasShopping(new AfricanShopping);
    proxy->BuyGoods(new Goods(true, "象牙"));
    delete proxy;
}

int main() {

    // test01();
    test02();

    system("pause");
    return EXIT_SUCCESS;
}