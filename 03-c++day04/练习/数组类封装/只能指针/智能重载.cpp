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
		cout << "年龄为：" << age << endl;
	
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

	//重载
	Person & operator*()
	{
		return * this->person;
	}


	~smartPointer()
	{
		cout << "析构函数调用" << endl;
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
	sp->show();//sp->->show()编译器做了优化
	(*sp).show();
}





int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}