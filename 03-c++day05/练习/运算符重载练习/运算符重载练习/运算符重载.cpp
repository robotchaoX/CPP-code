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
	//����ǰ��++�����
	
	Person & operator++()
	{
		 this->age++;
		 return *this;
	}
	//���غ���++�����
	Person &operator++(int)
	{
		Person tem = *this;
		return tem;
		this->age++;
	}

	//���ظ�ֵ�����



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