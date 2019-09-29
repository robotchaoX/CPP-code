#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{

public:
	Person()
	{
	//m_Age=10;//在构造函数中初始化，用类名调用时，不会调用构造函数
	
	}
	//放在全局静态区
	static int m_Age;//加入static就是静态成员变量 会共享数据
	//静态成员变量，在类内声明，类外进行初始化
	//静态成员变量 也是有权限的
	int m_A;

	//静态成员函数
	//不可以访问 普通成员变量
	//可以访问静态成员函数
	static void func()
	{
		//m_A=10;
		m_Age = 100;
		cout << "func调用" << endl;
	}

	//普通成员函数 可以访问普通成员变量，也可以访问静态成员变量
	void myFunc()
	{
		m_A = 200;
		m_Age = 200;
	}

private:
	static int m_other;//私有权限 再类外不能访问
	static void func2()
	{
		cout << "func2调用" << endl;
	}

};

//类外初始化格式 成员变量类型 作用域::成员变量名
int Person::m_Age = 0;//类外初始化实现
int Person::m_other = 10;//私有静态成员变量可在类外初始化
//int Person::m_other = 6666;静态成员变量不可以多次初始化
//int Person::m_Age;

void test()

{

	//1、通过对象访问属性
	Person p1;
	p1.m_Age = 10;

	Person p2;
	p2.m_Age = 20;
	cout << "p1 =" << p1.m_Age << endl;
	cout << "p2 =" << p2.m_Age << endl;
	//2、通过类名访问属性
	cout << "通过类名访问Age" << Person::m_Age << endl;
	//cout << "通过类名访问私有成员" << Person::m_other << endl;无法访问
	//静态成员函数调用
	p1.func();
	p2.func();
	Person::func();

	//静态成员函数 也是有权限
	//Person::func2();

}




int main(){


	test();

	system("pause");
	return EXIT_SUCCESS;
}