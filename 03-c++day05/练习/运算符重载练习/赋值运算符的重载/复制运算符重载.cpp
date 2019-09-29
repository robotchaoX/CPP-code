#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person(char *str)
	{
		this->m_str = new char[strlen(str) + 1];
		strcpy(this->m_str, str);
	}
	Person &operator=(Person &p1)
	{
		if (this->m_str != NULL)
		{
			delete this->m_str;
			this->m_str = NULL;
		}
		this->m_str = new char[strlen(p1.m_str) + 1];
		strcpy(this->m_str, p1.m_str);
		return *this;
	}

	~Person()
	{
		if (this->m_str != NULL)
		{
			delete []this->m_str;
			this->m_str = NULL;
		}
	}
	char *m_str;
};





void test()
{
	Person p1("马云");
	Person p2("李彦宏");
	Person p3("任正非");
	p1 = p2 = p3;
	cout << p1.m_str << endl;
}





int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}