#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
	friend ostream & operator<<(ostream &cout, Person &p1);
public:
	Person(){};
	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}

private:

	int m_A;
	int m_B;

};

ostream & operator<<(ostream &cout, Person &p1)
{

	cout << "p1.m_A=" << p1.m_A << " p1.m_B=" << p1.m_A;
	return cout;

}


void test()
{
	Person p1(10,10);
	cout << p1 << endl;
}







int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}