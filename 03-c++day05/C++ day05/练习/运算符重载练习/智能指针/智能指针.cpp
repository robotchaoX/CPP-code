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
		cout << "����Ϊ��" << this->m_age << endl;
	}
	~Person()
	{
		cout << "Person����������" << endl;
	}
	int m_age;
};


//����ָ��
//�������� ����Ա���ڶ��Ͽ��ٵĿռ�
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
			cout << "����ָ��ĵ���������" << endl;
		}
	}

	Person* person;
};



//д����ָ�� 
//1���ڲ�ά��һ��ָ������ָ��һ����Ҫ����������������
//2�����������ͷŵ����ָ��
//3�������Ҫ��ָ��һ�����ʹ��������Ҫ����->��*

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