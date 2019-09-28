#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	//类的静态成员属性
	static int sNum;
private:
	static int sOther;
};
//类外初始化，初始化时不加static
int Person::sNum = 0; 
int Person::sOther = 0;


int main(){

	//1、通过类名直接访问
	Person::sNum = 100;
	cout << "Person::sNum:" << Person::sNum << endl;



	//2、通过对象来访问
	Person p1, p2;
	p1.sNum = 200;
	cout << "p1.sNum" << p1.sNum << endl;
	cout << "p2.sNum" << p2.sNum << endl;


	//3、静态成员也有访问权限，类外不能访问私有成员
	//cout << "Peeson::s0ther" << Person::sOther << endl;不可访问
	Person p3;
	//cout << "p3.sOther" << p3.sOther << endl;不可访问



	system("pause");
	return EXIT_SUCCESS;
}