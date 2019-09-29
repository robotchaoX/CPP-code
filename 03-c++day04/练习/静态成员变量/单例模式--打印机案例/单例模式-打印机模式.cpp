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
		cout << "��ӡ��ʹ���˴���Ϊ" << m_Count << endl;
	}


private:
	//���������������̬��Ա�����������������ʼ��
	static Printer* singlePrinter;
	int m_Count;

};


Printer *Printer::singlePrinter = new Printer;

void test()
{
	//Printer::getInstance();
	Printer::getInstance()->printText("��ְ����");

}



int main(){

	


	test();


	system("pause");
	return EXIT_SUCCESS;
}