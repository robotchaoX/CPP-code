#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{

public:
	Person(){};
	Person(int a, int b) :m_A(a), m_B(b){}
	


	int m_A;
	int m_B;

};



Person& operator+(Person &p1,Person &p)
{

	Person temp;
	temp.m_A = p1.m_A + p.m_A;
	temp.m_B = p1.m_A + p.m_B;
	return temp;
}



void test()
{
	Person p1(10, 10);
	Person p2(10, 10);
	Person p3;

	p3 = p1 + p2;

	cout << p3.m_A << endl;
	cout << p3.m_B << endl;
	



}


int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}