#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//分类
//按照参数进行分类 1、无参构造函数(默认构造函数 2、有参构造函数
//按照类型进行分类 1、普通构造函数 2、拷贝构造函数
class Person
{
public://构造和析构必须写在public下才可以调用
	Person()//默认 、无参构造函数
	{
		cout << "默认构造函数调用" << endl;
	
	}
	Person(int a)
	{
		cout << "有参函数和调用" << endl;

	
	}
	Person(const Person &p)//拷贝构造函数
	{
		m_Age = p.m_Age;
		cout << "拷贝构造函数调用" << endl;
	}

	~Person()
	{
		cout << "析构函数调用" << endl;
	}

	int m_Age;
};
void test()
{
	//构造函数调用方式
	//括号调用
	//Person p1(1);//有参
	//p1.m_Age = 10;
	//Person p2(p1);
	//cout << "p2的年龄" << p2.m_Age << endl;
	//Person p3;//默认构造函数 不要加() person p3();编译器认为这行是函数的声明
	//显示法调用
	//Person p4 = Person(100);//与Person p4(100);等价
	//Person p5 = Person(p4);//与Person p5(p4);等价
	//Person(100);//匿名对象，特点是如果编译器发现了对象是匿名的，那么这行代码结束后就释放这个对象
	//不能用拷贝构造函数 初始化匿名对象
	//Person p6 = Person(p5);//如果写成左值，编译器认为你写成 Person p5对象的声明，如果写成右值，那么可以

	Person p7 = 100;//相当与调用了Person p7 = Person(100),隐式类型转换
	//相当于 Person p8=Person(p7);
}




int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}