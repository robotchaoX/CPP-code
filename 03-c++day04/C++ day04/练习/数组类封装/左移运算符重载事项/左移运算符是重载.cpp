#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//左移运算符重载
class Person
{
public:

	Person(){};

	Person(int a)
	{
		this->m_P = a;
	
	}


	int m_P;

};
//左移运算符在全局函数实现
ostream& operator<< (ostream & cout, Person & p)
{
	cout <<p.m_P;
	return cout;
}


void test()
{
	Person p1(10);
	cout << p1;

}




int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}