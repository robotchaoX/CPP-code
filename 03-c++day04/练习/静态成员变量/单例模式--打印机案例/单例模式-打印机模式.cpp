#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Printer
{

private:
	Printer(){ m_Count = 0; }

	Printer(const Printer &p);

public:
	static Printer *getInstance()
	{
		return singlePrinter;
	}

	void printText(string text)
	{
		cout << text << endl;
		m_Count++;
		cout << "打印机使用了次数为" << m_Count << endl;
	}


private:
	//访问这个变量，静态成员变量类内声明类外初始化
	static Printer* singlePrinter;
	int m_Count;

};


Printer *Printer::singlePrinter = new Printer;

void test()
{
	//Printer::getInstance();
	Printer::getInstance()->printText("离职报告");

}



int main(){

	


	test();


	system("pause");
	return EXIT_SUCCESS;
}