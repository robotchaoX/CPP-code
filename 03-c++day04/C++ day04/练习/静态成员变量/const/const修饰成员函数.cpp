#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Person
{
public:
	Person()//���캯���ͽ�������������ʹ�������޶���
	{
		 this->age = 0;
		this->top = 0;
	}
	void show()const
	{
		top = 100;
		cout << "age =" << age << endl;
		cout << "top =" << top << endl;
	}

	void showinfo()
	{
		age = 100;
		top = 100;
		cout << "age=" << age << endl;
		cout << "top=" << top << endl;
	}

		 int age;
	mutable int top;

};

void test()
{
	Person p1;
	p1.show();
	//p1.showinfo();
}


int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}