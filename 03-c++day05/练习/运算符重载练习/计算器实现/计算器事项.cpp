#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:

	virtual void counter() = 0;

	void seta(int a)
	{
		this->m_a = a;
	}
	void setb(int b)
	{
		this->m_b = b;
	}

	int m_a;
	int m_b;

};


class add :public Person
{
public:
	virtual void counter()
	{
		cout<< this->m_a + this->m_b<<endl;
	}

};


class cheng :public Person
{
public:
	virtual void counter()
	{
		cout << this->m_a*this->m_b<<endl;
	}
};



void test()
{
	cheng p1;
	p1.seta(10);
	p1.setb(10);
	p1.counter();
	add a1;
	a1.seta(10);
	a1.setb(10);
	a1.counter();
	Person *p = new add;
	p->seta(4);
	p->setb(4);
	p->counter();


}




int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}