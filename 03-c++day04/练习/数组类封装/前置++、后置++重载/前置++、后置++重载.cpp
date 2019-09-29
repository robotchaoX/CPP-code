#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
	friend  ostream & operator<<(ostream &cout, Person &p1);
	friend Person & operator++(Person &p);
public:
	Person()
	{
		m_A = 0;
	};

	Person & operator++()
	{
		this->m_A++;
		return *this;
	}
	//后置加加返回的是一个值，后置加加要加一个占位
	//后置加加先保存它的值
	Person operator++(int)
	{
		Person temp = *this;
		this->m_A++;
		return temp;
	}



private:
	int m_A;
};

Person & operator++(Person &p)
{
	p.m_A++;
	return p;
}



//重载<<运算符
 ostream & operator<<(ostream &cout, Person &p1)
{
	cout << p1.m_A;
 return cout;
}



 void test()
 {
	
	 Person p1;
	 
	 cout << p1++<<endl;
	 
	 //cout << ++p1;
 
 
 }





int main(){
	test();


	system("pause");
	return EXIT_SUCCESS;
}