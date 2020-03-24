#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Infomation;

//抽象观察者
class AbstractGang {
  public:
    virtual void Update(Infomation *) = 0;
    virtual string GetGangName() = 0;
};

//江湖消息
class Infomation {
  public:
    Infomation(AbstractGang *beat, AbstractGang *beaten) {
        this->Beat = beat;
        this->Beaten = beaten;
    }
    AbstractGang *Beat; //打人的帮派
    AbstractGang *Beaten; //被打的帮派
};

//华山派坐等百晓生的广播
class HuashanGang : public AbstractGang {
  public:
    HuashanGang() {
        m_GangName = "华山派";
    }
    virtual void Update(Infomation *info) {
        if (info->Beat == this && info->Beaten != this) {
            cout << "打死" << info->Beaten->GetGangName() << "," << this->GetGangName() << "最厉害!" << endl;
        } else if (info->Beat != this && info->Beaten != this) {
            cout << this->GetGangName() << "坐看" << info->Beat->GetGangName() << "和" << info->Beaten->GetGangName()
                 << "干架!" << endl;
        } else if (info->Beat != this && info->Beaten == this) {
            cout << info->Beat->GetGangName() << "干我们" << this->GetGangName() << "，我们要报仇!" << endl;
        }
    }
    virtual string GetGangName() {
        return m_GangName;
    }

  private:
    string m_GangName;
};

//昆仑派坐等百晓生的广播
class KunlunGang : public AbstractGang {
  public:
    KunlunGang() {
        m_GangName = "昆仑派";
    }
    virtual void Update(Infomation *info) {
        if (info->Beat == this && info->Beaten != this) {
            cout << "打死" << info->Beaten->GetGangName() << "," << this->GetGangName() << "最厉害!" << endl;
        } else if (info->Beat != this && info->Beaten != this) {
            cout << this->GetGangName() << "坐看" << info->Beat->GetGangName() << "和" << info->Beaten->GetGangName()
                 << "干架!" << endl;
        } else if (info->Beat != this && info->Beaten == this) {
            cout << info->Beat->GetGangName() << "干我们" << this->GetGangName() << "，我们要报仇!" << endl;
        }
    }
    virtual string GetGangName() {
        return m_GangName;
    }

  private:
    string m_GangName;
};

//武当派坐等百晓生的广播
class WudangGang : public AbstractGang {
  public:
    WudangGang() {
        m_GangName = "武当派";
    }
    virtual void Update(Infomation *info) {
        if (info->Beat == this && info->Beaten != this) {
            cout << "打死" << info->Beaten->GetGangName() << "," << this->GetGangName() << "最厉害!" << endl;
        } else if (info->Beat != this && info->Beaten != this) {
            cout << this->GetGangName() << "坐看" << info->Beat->GetGangName() << "和" << info->Beaten->GetGangName()
                 << "干架!" << endl;
        } else if (info->Beat != this && info->Beaten == this) {
            cout << info->Beat->GetGangName() << "干我们" << this->GetGangName() << "，我们要报仇!" << endl;
        }
    }
    virtual string GetGangName() {
        return m_GangName;
    }

  private:
    string m_GangName;
};

//百晓生 - 大嘴巴子
class Baixiaosheng {
  public:
    void addGang(AbstractGang *gang) {
        m_list.push_back(gang);
    }
    void setInfomation(Infomation *info) {
        pInfo = info;
    }
    void Notify() {
        for (list<AbstractGang *>::iterator it = m_list.begin(); it != m_list.end(); it++) {
            (*it)->Update(pInfo);
        }
    }

  private:
    list<AbstractGang *> m_list;
    Infomation *pInfo;
};

void test01() {

    AbstractGang *wudang = new WudangGang; //武当派
    AbstractGang *kunlun = new KunlunGang; //昆仑派
    AbstractGang *huashan = new HuashanGang; //华山派

    Baixiaosheng *baixiaosheng = new Baixiaosheng; //百晓生 大嘴巴子
    baixiaosheng->addGang(wudang);
    baixiaosheng->addGang(kunlun);
    baixiaosheng->addGang(huashan);

    Infomation *pInfo = new Infomation(wudang, huashan); //创建江湖消息  武当打华山
    baixiaosheng->setInfomation(pInfo); //告诉百晓生武当打华山了

    //大嘴巴开始向各大门派发消息了
    baixiaosheng->Notify();
}

// 广播武林打斗消息
int main() {

    test01();

    return EXIT_SUCCESS;
}
