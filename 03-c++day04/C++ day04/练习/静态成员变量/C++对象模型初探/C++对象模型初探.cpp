#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//this���Խ��������ͻ
class Person
{
public:

	Person( int age)
	{
		this->age = age;
	}

	void compareAge(Person &p)
	{
		if (this->age == p.age)
		{
			cout << "�������" << endl;
		}
		else
		{
			cout << "���䲻���" << endl;
		}
	}

	Person& PlusAge(Person &p)
	{
		age += p.age; 
		return  * this;	
	}
	
	int age;
};



void test()
{
	Person p1(10);
	cout << p1.age << endl;
	Person p2(10);
	p1.compareAge(p2);
	//p1.PlusAge(p2)�൱��p1
	p1.PlusAge(p2).PlusAge(p2);//��ʽ���
	cout << p1.age << endl;	
}




int main()
{

	test();
	system("pause");
	return EXIT_SUCCESS;
}