#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//class MyClass
//{
//public:
//	MyClass()
//	{
//		cout << "Ĭ�Ϲ��캯��" << endl;
//	}
//	MyClass(int a)
//	{
//		cout << "�вι��캯��" << endl;
//	
//	}
//
//	MyClass(const MyClass & m)
//	{
//		
//	}
//	int m_A;
//};
//ϵͳĬ�ϸ�һ�����ṩ3������ Ĭ�Ϲ��졢�������졢��������
//1���������ṩ���вι��캯������ôϵͳ�Ͳ����ٸ������ṩĬ�Ϲ��캯��
//����ϵͳ�����ṩĬ�Ͽ������캯�������м򵥵�ֵ����


//2���������ṩ��


using namespace std;

class MyClass
{
public:
	//MyClass()
	//{
	//	cout << "Ĭ�Ϲ��캯��" << endl;
	//}

	MyClass(int a)
	{
		cout << "�вι��캯��" << endl;
	}
	//
	//MyClass(const MyClass& m)
	//{
	//}
	int m_A;


};

void test01()
{
	MyClass c1(1);
	c1.m_A = 10;
	MyClass c2(c1);
	cout << c2.m_A << endl;

	cout << "c1" << c1.m_A << endl;
}


//2���������ṩ�� �������죬��ôϵͳ�Ͳ����ṩ����������

int main(){


	test01();
	system("pause");
	return EXIT_SUCCESS;
}