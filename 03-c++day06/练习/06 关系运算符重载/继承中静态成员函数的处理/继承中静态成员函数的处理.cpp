#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Base
{
public:
	Base()
	{
		cout << "Base m_A:" << this->m_A << endl;
	}
	static void show()
	{
		cout << "���๹�����" << endl;
	}



	static int m_A;
};

int Base::m_A = 10;

class Son:public Base
{
public:
	Son()
	{
		cout << "Son m_A:" << this->m_A << endl;
	}
	static void show()
	{
		cout << "���๹�����" << endl;
	
	}



	static int m_A;
};


int Son::m_A = 66;


//�ȵ��ø����еĹ��캯��
void test()
{
	Son p1;
	
	cout << p1.m_A << endl;
	cout << p1.Base::m_A << endl;
	Son::show();
	Son::Base::show();
}



int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}