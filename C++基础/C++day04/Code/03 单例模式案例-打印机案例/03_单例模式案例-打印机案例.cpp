#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Printer {
  private:
    // 3.构造函数 私有化
    Printer() {
        // m_Count = 0;
        cout << "...构造函数" << endl;
    }; // 构造
    Printer(const Printer &p) {
        cout << "...拷贝构造" << endl;
    }; // 拷贝

  public:
    // 2.提供对外接口
    static Printer *getInstance() {
        return singlePrinter; // 返回static类指针
    }

    // 普通方法
    void printText(string text) {
        cout << text << endl;
        m_Count++;
        cout << "printText打印机使用了次数为： " << m_Count << endl;
    }

    // static方法
    static void printText_static(string text) {
        cout << text << endl;
        m_Count_static++;
        cout << "printText_static打印机使用了次数为： " << m_Count_static << endl;
    }

  private:
    // 1.静态类指针属性 私有化
    static Printer *singlePrinter; // ststic类指针
    // 普通属性
    int m_Count;
    // static属性
    static int m_Count_static;
};
// static 类内定义 类外实现
Printer *Printer::singlePrinter = new Printer; // 初始化调用构造函数
int Printer::m_Count_static = 0;

void test01() {
    //拿到打印机,只有一个对象
    Printer *printer = Printer::getInstance();

    printer->printText("升级申请");
    printer->printText("退休申请");
    printer->printText_static("升级申请");
    printer->printText_static("退休申请");
    // 普通方法和static方法都可以

    cout << "-----" << endl;

    // 同一个类对象指针
    Printer *printer2 = Printer::getInstance();

    printer2->printText("离职报告");
    printer2->printText("入职报告");
    printer2->printText_static("离职报告");
    printer2->printText_static("入职报告");
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}