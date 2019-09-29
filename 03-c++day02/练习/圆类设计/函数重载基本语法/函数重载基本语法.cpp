#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//函数重载
//c++中函数名称可以重复
//必须在同一个作用域，函数名称相同
//函数的参数个数不同或者类型不同或者顺序 不同
void func()
{
	cout << "无参数的func" << endl;
}
void func(int a)
{
	cout << "有参数的func(int a)" << endl;
}

void func(double a)
{
	cout << "有参数的func(double a)" << endl;
}

void func(double a, int b)
{
	cout << "有参数的func(double a, int b)" << endl;
}
//返回值不可以作为函数重载条件
//int func(int a,double b)
//{
//cout<<"有参数defunc(int a,double b)"<<endl;
//return 1;
//}
void test01()
{
//func(1.1,3);
	func(1, 3.14);
}
//当函数重载碰到默认参数时候，要注意避免二义性问题
void func2(int a, int b = 10)
{

}
void func2(int a)
{


}
//产生二义性
void test02()
{
	//func2(10);
}

//引用的重载版本
void fun3(int &a)//引用必须要引合法的内存空间
{
	cout << "int &a" << endl;
}
void fun3(const int &a)//const也是可作为重载条件 int tmp=10 ;const int &a=tmp;
{
	cout << "cout int &a" << endl;

}

void test03()
{
//int a=10;
	//func3(10);

}

int main(){



	system("pause");
	return EXIT_SUCCESS;
}