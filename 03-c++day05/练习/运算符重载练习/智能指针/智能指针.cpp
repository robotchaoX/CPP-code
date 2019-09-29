#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<memory.h>
class Person
{
public:
	Person(int age)
	{
		this->m_age = age;
	}
	void showage()
	{
		cout << "年龄为：" << this->m_age << endl;
	}
	~Person()
	{
		cout << "Person的析构调用" << endl;
	}
	int m_age;
};


//智能指针
//用来管理 程序员开在堆上开辟的空间
class smartPointer
{
public:
	smartPointer(Person *person)
	{
		this->person = person;
	}
	Person *operator->()
	{
		return this->person;
	}
	Person & operator*()
	{
		return * this->person;
	}
	~smartPointer()
	{
		if (this->person != NULL)
		{
			delete this->person;
			this->person = NULL;
			cout << "智能指针的的析构调用" << endl;
		}
	}

	Person* person;
};



//写智能指针 
//1、内部维护一个指针用于指向一个需要管理的类或其他类型
//2、在析构中释放掉这个指针
//3、如果想要像指针一样访问管理的类需要重载->和*

void test()
{
	smartPointer p1(new Person(10));


	p1->showage();
	(*p1).showage();

	cout << p1->m_age << endl;
}





int main(){

	
	
	test();
	system("pause");
	return EXIT_SUCCESS;
}