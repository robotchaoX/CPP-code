#include<iostream>


using namespace std;

class Person
{
public:
	
	Person(): m_A(10), m_B(20), m_C(30)
	{
		cout << "调用无参构造函数" << endl;
	}

	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c)
	{
		cout << "调用有参构造函数" << endl;
	}

	int m_A;
	int m_B;
	int m_C;




};

void test01()
{

	Person p1(50, 60, 70);
	cout << "p1的m_A :" << p1.m_A << endl;
	cout << "p1的m_B :" << p1.m_B << endl;
	cout << "p1的m_C :" << p1.m_C << endl;

	Person p2;
	cout << "p2的m_A:" << p2.m_A << endl;
	cout << "p2的m_B:" << p2.m_B << endl;
	cout << "p2的m_C:" << p2.m_C << endl;

}


void main()
{

	test01();
	system("pause");

}