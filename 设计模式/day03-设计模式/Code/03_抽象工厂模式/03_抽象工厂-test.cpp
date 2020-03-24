#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//抽象显卡
class AbstractGraphics {
  public:
    virtual void work() = 0;
};

//因特尔显卡
class IntelGraphics : public AbstractGraphics {
  public:
    virtual void work() {
        cout << "因特尔显卡开始工作..." << endl;
    }
};

//英伟达显卡
class NvidiaGraphics : public AbstractGraphics {
  public:
    virtual void work() {
        cout << "英伟达显卡开始工作..." << endl;
    }
};

//金士顿显卡
class KingstonGraphics : public AbstractGraphics {
  public:
    virtual void work() {
        cout << "金士顿显卡开始工作..." << endl;
    }
};

//抽象CPU
class AbstractCPU {
  public:
    virtual void work() = 0;
};

//因特尔CPU
class IntelCPU : public AbstractCPU {
  public:
    virtual void work() {
        cout << "因特尔CPU开始工作..." << endl;
    }
};

//英伟达CPU
class NvidiaCPU : public AbstractCPU {
  public:
    virtual void work() {
        cout << "英伟达CPU开始工作..." << endl;
    }
};

//金士顿CPU
class KingstonCPU : public AbstractCPU {
  public:
    virtual void work() {
        cout << "金士顿CPU开始工作..." << endl;
    }
};

//抽象内存
class AbstractMemory {
  public:
    virtual void work() = 0;
};

//因特尔内存
class IntelMemory : public AbstractMemory {
  public:
    virtual void work() {
        cout << "因特尔内存开始工作..." << endl;
    }
};

//英伟达内存
class NvidiaMemory : public AbstractMemory {
  public:
    virtual void work() {
        cout << "英伟达内存开始工作..." << endl;
    }
};

//金士顿内存
class KingstonMemory : public AbstractMemory {
  public:
    virtual void work() {
        cout << "金士顿内存开始工作..." << endl;
    }
};

//计算机
class Computer {
  public:
    Computer() {
        this->pCPU = NULL;
        this->pGraphics = NULL;
        this->pMemory = NULL;
    }
    void setCPU(AbstractCPU *cpu) {
        pCPU = cpu;
    }
    void setGraphics(AbstractGraphics *graphics) {
        pGraphics = graphics;
    }
    void setMemory(AbstractMemory *memory) {
        pMemory = memory;
    }

    //启动电脑
    void run() {
        if (NULL != pCPU) {
            this->pCPU->work();
        }
        if (NULL != this->pGraphics) {
            this->pGraphics->work();
        }
        if (NULL != this->pMemory) {
            this->pMemory->work();
        }
    }

  private:
    AbstractCPU *pCPU;
    AbstractGraphics *pGraphics;
    AbstractMemory *pMemory;
};

//抽象工厂
class AbstractFactory {
  public:
    virtual AbstractCPU *CreateCPU() = 0;
    virtual AbstractGraphics *CreateGraphics() = 0;
    virtual AbstractMemory *CreateMemory() = 0;
};

//生产第一种电脑的工厂
class FirstComputerFactory : public AbstractFactory {
  public:
    virtual AbstractCPU *CreateCPU() {
        return new IntelCPU;
    }
    virtual AbstractGraphics *CreateGraphics() {
        return new IntelGraphics;
    }
    virtual AbstractMemory *CreateMemory() {
        return new IntelMemory;
    }
};

//生产第二种电脑的工厂
class SecondComputerFactory : public AbstractFactory {
  public:
    virtual AbstractCPU *CreateCPU() {
        return new IntelCPU;
    }
    virtual AbstractGraphics *CreateGraphics() {
        return new NvidiaGraphics;
    }
    virtual AbstractMemory *CreateMemory() {
        return new KingstonMemory;
    }
};

void test01() {

    Computer *computer = new Computer;
    AbstractFactory *factory = NULL;
    AbstractCPU *cpu = NULL;
    AbstractGraphics *graphics = NULL;
    AbstractMemory *memory = NULL;

    //创建生产零件的工厂
    factory = new FirstComputerFactory;
    cpu = factory->CreateCPU();
    graphics = factory->CreateGraphics();
    memory = factory->CreateMemory();

    //组装第一台电脑
    computer->setCPU(cpu); //安装CPU
    computer->setGraphics(graphics); //安装显卡
    computer->setMemory(memory); //安装内存
    computer->run(); //启动电脑

    delete memory;
    delete graphics;
    delete cpu;
    delete factory;

    cout << "-------------------------" << endl;
    factory = new SecondComputerFactory;
    cpu = factory->CreateCPU();
    graphics = factory->CreateGraphics();
    memory = factory->CreateMemory();

    //组装第二台电脑
    computer->setCPU(cpu); //安装CPU
    computer->setGraphics(graphics); //安装显卡
    computer->setMemory(memory); //安装内存
    computer->run(); //启动电脑

    delete memory;
    delete graphics;
    delete cpu;
    delete factory;

    delete computer;
}

// 组装两台电脑,
// 1台（Intel的CPU，Intel的显卡，Intel的内存）,
// 1台（Intel的CPU， nvidia的显卡，Kingston的内存）
int main() {

    test01();

    return EXIT_SUCCESS;
}
