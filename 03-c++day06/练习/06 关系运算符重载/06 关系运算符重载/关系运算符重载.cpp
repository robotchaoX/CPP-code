#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person(){};
	Person(string str,int age)
	{
		this->m_str = str;
		this->age = age;
	}
	bool operator== (Person& p1)
	{
		if (p1.m_str == this->m_str&&this->age==p1.age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string m_str;
	int age;

};

void test()
{
	Person p1("����", 20);
	Person p2("����", 30);
	Person p3("����", 20);

	if (p1 == p3)
	{
		cout << "������ͬ" << endl;
	}
	else
	{
		cout << "���ǲ���ͬ" << endl;
	}

}



int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}