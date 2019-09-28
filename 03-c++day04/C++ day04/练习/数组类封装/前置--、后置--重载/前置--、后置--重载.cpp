#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "调用默认构造函数" << endl;
		this->m_A = 10;
	};
	

	Person & operator--()
	{
		this->m_A--;
		return *this;
	}
	Person operator--(int)
	{
		Person *temp = this;
		this->m_A--;
		return *temp;
	}

	int m_A;

};

void test()
{
	Person p1;
	cout << "p1.m_A=" << p1.m_A << endl;
	cout << "p1.m_A--:" << p1.m_A-- << endl;
	cout << "--p1.m_A:" << --p1.m_A << endl;
	cout << "p1.m_A:" << p1.m_A << endl;

}


int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}