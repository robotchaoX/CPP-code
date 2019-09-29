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
	}

	void show()
	{
		cout << "����Ϊ��" << age << endl;
	
	}

	int age;
};


class smartPointer
{
public:
	smartPointer(Person *person)
	{
		this->person =person;
	
	}
	//
	Person * operator->()
	{
		return this->person;
	}

	//����
	Person & operator*()
	{
		return * this->person;
	}


	~smartPointer()
	{
		cout << "������������" << endl;
		if (person != NULL)
		{
			delete this->person;
			this->person = NULL;
		}
	}

	Person *person;

};





void test()
{
	
	Person p1(10);
	Person *p2 = new Person(10);
	
	smartPointer sp(new Person(10));
	sp->show();//sp->->show()�����������Ż�
	(*sp).show();
}





int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}