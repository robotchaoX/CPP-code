#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{

public:
	Person(int i)
	{
		this->age=i;
	}
	//重载前置++运算符
	
	Person & operator++()
	{
		 this->age++;
		 return *this;
	}
	//重载后置++运算符
	Person &operator++(int)
	{
		Person tem = *this;
		return tem;
		this->age++;
	}

	//重载赋值运算符



		int age;
};


ostream & operator<<(ostream &couut, Person &p1)
{
	cout << p1.age;
	return cout;
}


void test()
{
	Person p1(10);
	++p1;
	//cout << p1.age << endl;
	cout << p1 << endl;
}




int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}