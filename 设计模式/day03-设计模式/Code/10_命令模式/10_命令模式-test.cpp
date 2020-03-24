#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
using namespace std;

//烤串大师
class SkewerMaster {
  public:
    void MakeChickenWings() {
        cout << "烤鸡翅!" << endl;
    }
    void MakeMutton() {
        cout << "烤羊肉!" << endl;
    }
};

//抽象烤串命令
class AbstractSkewerCommand {
  public:
    virtual void Make() = 0;
};

//烤鸡翅的命令
class MakeChickenWingsCommand : public AbstractSkewerCommand {
  public:
    MakeChickenWingsCommand(SkewerMaster *master) {
        pMaster = master;
    }
    virtual void Make() {
        pMaster->MakeChickenWings();
    }

  private:
    SkewerMaster *pMaster;
};

//烤羊肉的命令
class MakeMuttonCommand : public AbstractSkewerCommand {
  public:
    MakeMuttonCommand(SkewerMaster *master) {
        pMaster = master;
    }
    virtual void Make() {
        pMaster->MakeMutton();
    }

  private:
    SkewerMaster *pMaster;
};

//服务员
class Waiter {
  public:
    void addCommand(AbstractSkewerCommand *command) {
        m_list.push_back(command);
    }
    void submitCommand() {
        for (list<AbstractSkewerCommand *>::iterator it = m_list.begin(); it != m_list.end(); it++) {
            (*it)->Make();
        }
    }

  private:
    list<AbstractSkewerCommand *> m_list;
};

//测试
void test01() {

    //创建烧烤师傅
    SkewerMaster *master = new SkewerMaster;
    //创建烧烤命令
    AbstractSkewerCommand *command1 = new MakeChickenWingsCommand(master);
    AbstractSkewerCommand *command2 = new MakeMuttonCommand(master);
    //创建服务员
    Waiter *waiter = new Waiter;
    waiter->addCommand(command1);
    waiter->addCommand(command2);
    //服务员批量提交命令
    waiter->submitCommand();

    delete waiter;
    delete command2;
    delete command1;
    delete master;
}

// 根据命令模式，设计烤串场景
int main() {

    test01();

    return EXIT_SUCCESS;
}
