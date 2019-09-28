#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person(){};
	Person(int age)
	{
		this->age = age;
	};

	void show()
	{
		cout << this->age << endl;
	}

	int age;

};

class  smartPointer
{
public:
	smartPointer(Person* person)
	{
		this->person = person;
	};

	Person * operator->()
	{
		return  this->person;
	}
	Person & operator*()
	{
	
		return *this->person;
	}

	~smartPointer()
	{
		if (this->person != NULL)
		{
			delete person;
			person = NULL;
		}
	}
	Person* person;

};


void test()
{

	Person * p1 = new Person(10);
	p1->show();
	smartPointer sp(p1);
	sp->show();
	(*sp).show();
}





int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}