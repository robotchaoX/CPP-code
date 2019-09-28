#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Printer {
  private:
    Printer() { m_Count = 0; };  // 构造
    Printer(const Printer &p){}; // 拷贝

  public:
    static Printer *getInstance() {
        return singlePrinter; // 返回static类指针
    }

    void printText(string text) {
        cout << text << endl;
        m_Count++;
        cout << "打印机使用了次数为： " << m_Count << endl;
    }

  private:
    static Printer *singlePrinter; // ststic类指针
    int m_Count;
};

// static 类内定义 类外实现
Printer *Printer::singlePrinter = new Printer;

void test01() {
    //拿到打印机
    Printer *printer = Printer::getInstance();

    printer->printText("离职报告");
    printer->printText("入职报告");
    printer->printText("加薪申请");
    printer->printText("升级申请");
    printer->printText("退休申请");
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}