#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//class MyClass
//{
//public:
//	MyClass()
//	{
//		cout << "默认构造函数" << endl;
//	}
//	MyClass(int a)
//	{
//		cout << "有参构造函数" << endl;
//	
//	}
//
//	MyClass(const MyClass & m)
//	{
//		
//	}
//	int m_A;
//};
//系统默认给一个雷提供3个函数 默认构造、拷贝构造、析构构造
//1、当我们提供了有参构造函数，那么系统就不会再给我们提供默认构造函数
//但是系统还会提供默认拷贝构造函数，进行简单的值拷贝


//2、当我们提供了


using namespace std;

class MyClass
{
public:
	//MyClass()
	//{
	//	cout << "默认构造函数" << endl;
	//}

	MyClass(int a)
	{
		cout << "有参构造函数" << endl;
	}
	//
	//MyClass(const MyClass& m)
	//{
	//}
	int m_A;


};

void test01()
{
	MyClass c1(1);
	c1.m_A = 10;
	MyClass c2(c1);
	cout << c2.m_A << endl;

	cout << "c1" << c1.m_A << endl;
}


//2、当我们提供了 拷贝构造，那么系统就不会提供其他构造了

int main(){


	test01();
	system("pause");
	return EXIT_SUCCESS;
}